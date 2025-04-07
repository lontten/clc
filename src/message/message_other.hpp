//
// Created by lontten on 2025/4/5.
//

#pragma once
#include <cstdio>

namespace clc {
    MessageSelectType message_other(
        const std::string &title, const std::string &content,
        const MessageType type,
        const WinId pid,
        const LangType lang
    ) {
        printf("未知平台\n");
        return MessageSelectType::OK;
    }
}
