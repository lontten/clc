cmake_minimum_required(VERSION 3.30)
project(clc)

set(CMAKE_CXX_STANDARD 20)

# 设置全局包含目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加 GUI 库目录
add_subdirectory(src)

# 添加 examples 目录
add_subdirectory(examples)

# 如果 src 需要 lib 下的库，可以在这里统一添加
# include_directories(${CMAKE_SOURCE_DIR}/lib)
# target_link_libraries(pui_lib some_lib_from_lib_dir)