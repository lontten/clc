//
// Created by lontten on 2025/4/6.
//

#pragma once
#include <Windows.h>
#include <string>
#include <stdexcept>

namespace clc::utils {
    typedef unsigned long st;
    std::wstring utf8_to_wstring(const std::string &utf8_str);
}
