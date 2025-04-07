//
// Created by lontten on 2025/4/5.
//

#pragma once
#include <cstdio>

namespace clc {
    MessageSelectType message_mac(
        const std::string &title, const std::string &content,
        const MessageType type,
        const WinId pid,
        const LangType lang
    ) {
        printf("mac 未实现\n");
        return MessageSelectType::OK;
    }
}
