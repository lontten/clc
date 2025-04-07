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

    enum class MessageSelectType {
        OK = 1, // 确定按钮
        Cancel = 2, // 取消按钮
        Abort = 3, // 中止按钮
        Retry = 4, // 重试按钮
        Ignore = 5, // 忽略按钮
        Yes = 6, // 是按钮
        No = 7, // 无按钮
        TryAgain = 10, // 重试按钮（二次确认）
        Continue = 11 // 继续按钮
    };

    enum class LangType {
        AUTO, // 自动检测语言
        ENGLISH_US, // 美式英语
        CHINESE_SIMPLIFIED, // 简体中文
    };

    MessageSelectType message(
        const std::string &title, const std::string &content,
        MessageType type = MessageType::Ok,
        WinId pid = 0,
        LangType lang = LangType::AUTO
    );
}
