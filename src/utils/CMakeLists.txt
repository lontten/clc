set(UTILS_SOURCE string.cpp
)
add_library(utils_lib ${UTILS_SOURCE})
target_include_directories(utils_lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)