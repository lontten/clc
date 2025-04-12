//
// Created by lontten on 2025/4/5.
//


// 引入不同实现的头文件
#include "clc/app.h"
#include "clc/sys.h"

#include "sys_win.hpp"
#include "sys_mac.hpp"
#include "sys_linux.hpp"
#include "sys_other.hpp"

namespace clc {
    PowerInfo powerStatus() {
        return PLATFORM_CALL(powerStatus);
    }
}
