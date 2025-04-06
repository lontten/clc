add_subdirectory(utils)
add_subdirectory(win)
add_subdirectory(message)
add_library(clc_lib app.cpp)
target_link_libraries(clc_lib
        utils_lib
        win_lib
        message_lib
)