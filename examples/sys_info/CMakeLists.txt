# 设置项目名称
project(sys_info)

# 添加可执行文件
add_executable(sys_info main.cpp)

# 链接主项目的库
target_link_libraries(sys_info clc)