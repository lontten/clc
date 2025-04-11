//
// Created by lontten on 2025/4/5.
//

#pragma once
#include <cstdio>

namespace clc {
    MessageSelectType message_linux(
        const std::string &title, const std::string &content,
        const MessageType type,
        const WinId pid,
        const LangType lang
    ) {
        printf("linux 未实现\n");
        return MessageSelectType::OK;
    }
}
