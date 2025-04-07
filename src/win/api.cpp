//
// Created by lontten on 2025/4/5.
//

#include "clc/app.h"
#include "clc/win.h"

// 引入不同实现的头文件
#include "win_win.hpp"
#include "win_mac.hpp"
#include "win_linux.hpp"
#include "win_other.hpp"

namespace clc {
    int win(const std::string &title) {
        return PLATFORM_CALL(win, title);
    }
}
