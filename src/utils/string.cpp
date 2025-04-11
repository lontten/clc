//
// Created by lontten on 2025/4/6.
//
#include "utils/string.h"

namespace clc::utils {
    // 将UTF-8字符串转换为std::wstring（UTF-16）
    std::wstring utf8_to_wstring(const std::string &utf8_str) {
        if (utf8_str.empty()) {
            return std::wstring();
        }

        // 计算所需缓冲区大小（包含终止符）
        int wide_len = MultiByteToWideChar(
            CP_UTF8, // 代码页为UTF-8
            0, // 无特殊标志
            utf8_str.c_str(), // 输入字符串
            -1, // 自动计算长度（直到null终止符）
            nullptr, // 不提供输出缓冲区
            0 // 请求缓冲区大小
        );
        if (wide_len == 0) {
            throw std::runtime_error("MultiByteToWideChar failed. Error code: " + std::to_string(GetLastError()));
        }

        // 分配缓冲区并执行转换
        std::wstring wide_str;
        wide_str.resize(wide_len);
        if (MultiByteToWideChar(
                CP_UTF8,
                0,
                utf8_str.c_str(),
                -1,
                &wide_str[0], // 输出缓冲区
                wide_len
            ) == 0) {
            throw std::runtime_error("MultiByteToWideChar failed. Error code: " + std::to_string(GetLastError()));
        }

        // 移除自动添加的终止符（std::wstring会自行管理）
        wide_str.resize(wide_len - 1);
        return wide_str;
    }
}
