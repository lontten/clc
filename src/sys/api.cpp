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
    std::string formatBytes(long long bytes) {
        const char *units[] = {"B", "KB", "MB", "GB", "TB"};
        double value = bytes;
        int unitIndex = 0;

        // 循环判断单位层级
        while (value >= 1024 && unitIndex < 4) {
            value /= 1024;
            unitIndex++;
        }

        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << value << " " << units[unitIndex];
        return oss.str();
    }

    PowerInfo powerStatus() {
        return PLATFORM_CALL(powerStatus);
    }

    std::vector<DiskInfo> GetDiskInfo() {
        return PLATFORM_CALL(GetDiskInfo);
    }

    MemoryInfo GetMemoryInfo() {
        return PLATFORM_CALL(GetMemoryInfo);
    }
}
