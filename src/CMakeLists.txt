add_subdirectory(utils)
add_subdirectory(win)
add_subdirectory(message)
add_library(clc STATIC app.cpp)
target_link_libraries(clc
        utils_lib
        win_lib
        message_lib
)
target_include_directories(clc
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:include>
)