# 设置项目名称
project(hello)

# 添加可执行文件
add_executable(hello main.cpp)

# 链接主项目的库
target_link_libraries(hello clc)