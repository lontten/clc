//
// Created by lontten on 2025/4/5.
//


// 引入不同实现的头文件
#include "clc/app.h"

#include "message_win.hpp"
#include "message_mac.hpp"
#include "message_linux.hpp"
#include "message_other.hpp"

namespace clc {
    int message(const std::string &title, const std::string &content,
                const MessageType type, const WinId pid, const LangType lang) {
        return PLATFORM_CALL(message, title, content, type, pid, lang);
    }
}
