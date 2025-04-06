//
// Created by Lontten on 2025/4/2.
//
#pragma once
#include <string>

#include "clc/win.h"

namespace clc {
    enum class MessageType {
        AbortRetryIgnore, // 包含三个按钮：中止/重试/忽略
        Help, // 添加帮助按钮，触发 WM_HELP 消息
        Ok, // 默认单按钮：确定
        OkCancel, // 确定/取消双按钮
        RetryCancel, // 重试/取消双按钮
        YesNo, // 是/否双按钮
        YesNoCancel, // 是/否/取消三按钮
    };

    int message(const std::string &title, const std::string &content,
                MessageType type = MessageType::Ok, WinId pid = 0);
}
