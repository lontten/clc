//
// Created by Lontten on 2025/4/2.
//
#pragma once
namespace clc {
    // 定义不同平台的函数名标识符
#if defined(_WIN32)
#define OS_NAME win
#elif defined(__APPLE__) && defined(__MACH__)
#define OS_NAME mac
#elif defined(__linux__)
#define OS_NAME linux
#else
#define OS_NAME other
#endif


    // 辅助宏用于拼接标识符
#define CONCAT(a, b) a##b
#define CONCAT_EXPAND(a, b) CONCAT(a, b)

    // 最终的功能宏（支持可变参数）
#define PLATFORM_CALL(name, ...) CONCAT_EXPAND(name##_, OS_NAME)(__VA_ARGS__)


    int app();
}
