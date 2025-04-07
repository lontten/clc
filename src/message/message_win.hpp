//
// Created by lontten on 2025/4/5.
//

#pragma once

// 强制启用Unicode编码（现代Windows开发必备）
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>  // 包含Windows API核心头文件
#include <string>

#include "clc/message.h"
#include "clc/win.h"
#include "clc/utils/string.h"

namespace clc {
    // AbortRetryIgnore = 0x00000002L, // 包含三个按钮：中止/重试/忽略
    // Help = 0x00004000L, // 添加帮助按钮，触发 WM_HELP 消息
    // Ok = 0x00000000L, // 默认单按钮：确定
    // OkCancel = 0x00000001L, // 确定/取消双按钮
    // RetryCancel = 0x00000005L, // 重试/取消双按钮
    // YesNo = 0x00000004L, // 是/否双按钮
    // YesNoCancel = 0x00000003L // 是/否/取消三按钮
    constexpr UINT messageTypeConvertToPlatform(const MessageType type) {
        switch (type) {
            case MessageType::AbortRetryIgnore: return MB_ABORTRETRYIGNORE;
            case MessageType::Help: return MB_HELP;
            case MessageType::Ok: return MB_OK;
            case MessageType::OkCancel: return MB_OKCANCEL;
            case MessageType::RetryCancel: return MB_RETRYCANCEL;
            case MessageType::YesNo: return MB_YESNO;
            case MessageType::YesNoCancel: return MB_YESNOCANCEL;
            default: return MB_OK;
        }
    }

    constexpr UINT langConvertToPlatform(const LangType lang) {
        switch (lang) {
            case LangType::AUTO: return 0;
            case LangType::ENGLISH_US: return MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US);
            case LangType::CHINESE_SIMPLIFIED: return MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED);
            default: return 0;
        }
    }

    inline MessageSelectType message_win(
        const std::string &title, const std::string &content,
        const MessageType type,
        const WinId pid,
        const LangType lang
    ) {
        const auto title1 = utils::utf8_to_wstring(title);
        const auto content1 = utils::utf8_to_wstring(content);
        const auto title2 = title1.c_str();
        const auto content2 = content1.c_str();
        const auto t = messageTypeConvertToPlatform(type);
        const auto l = langConvertToPlatform(lang);

        const auto ret = MessageBoxExW(nullptr, content2, title2, t, l);
        switch (ret) {
            case IDABORT: return MessageSelectType::Abort;
            case IDCANCEL: return MessageSelectType::Cancel;
            case IDCONTINUE: return MessageSelectType::Continue;
            case IDIGNORE: return MessageSelectType::Ignore;
            case IDNO: return MessageSelectType::No;
            case IDOK: return MessageSelectType::OK;
            case IDRETRY: return MessageSelectType::Retry;
            case IDTRYAGAIN: return MessageSelectType::TryAgain;
            case IDYES: return MessageSelectType::Yes;
            default: return MessageSelectType::OK;
        }
    }
}
