add_subdirectory(win)
add_library(clc_lib app.cpp)
target_link_libraries(clc_lib win_lib)