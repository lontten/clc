//
// Created by lontten on 2025/4/5.
//

#pragma once

// 强制启用Unicode编码（现代Windows开发必备）
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>  // 包含Windows API核心头文件
#include <vector>

#include "clc/sys.h"

namespace clc::platform {
    inline PowerInfo powerStatus_win() {
        SYSTEM_POWER_STATUS status;
        ZeroMemory(&status, sizeof(status)); // 显式初始化结构体

        // 优先处理 API 调用失败
        if (!GetSystemPowerStatus(&status)) {
            return PowerInfo{
                .battery_percentage = -1,
                .power_status = PowerStatus::Unknown
            };
        }

        // 严格按 Win32 API 规范处理状态
        // -------------------------------
        // 1. 处理无电池情况 (BATTERY_FLAG_NO_BATTERY)
        if (status.BatteryFlag & 0x80) {
            return PowerInfo{
                .battery_percentage = 0, // 符合 MSDN 的无电池建议值
                .power_status = PowerStatus::None
            };
        }

        // 2. 处理无效电池百分比 (255)
        if (status.BatteryLifePercent == 255) {
            return PowerInfo{
                .battery_percentage = -1,
                .power_status = PowerStatus::Unknown
            };
        }

        // 3. 结合 ACLineStatus 判断电源状态
        if (status.ACLineStatus == 1) {
            // 交流电源在线
            // 严格按充电标志判断 (BATTERY_FLAG_CHARGING)
            if (status.BatteryFlag & 0x08) {
                return PowerInfo{
                    .battery_percentage = status.BatteryLifePercent,
                    .power_status = PowerStatus::Charging
                };
            }
            // 交流在线但未充电的特殊情况
            return PowerInfo{
                .battery_percentage = status.BatteryLifePercent,
                .power_status = PowerStatus::OnBattery
            };
        }

        // 4. 处理电池低电量状态
        if (status.BatteryFlag & 0x04) {
            // BATTERY_FLAG_LOW
            return PowerInfo{
                .battery_percentage = status.BatteryLifePercent,
                .power_status = PowerStatus::LowBattery
            };
        }

        if (status.BatteryFlag & 0x02) {
            // BATTERY_FLAG_CRITICAL
            return PowerInfo{
                .battery_percentage = status.BatteryLifePercent,
                .power_status = PowerStatus::CriticalBattery
            };
        }

        // 默认情况：使用电池
        return PowerInfo{
            .battery_percentage = status.BatteryLifePercent,
            .power_status = PowerStatus::OnBattery
        };
    }


    // 获取磁盘信息
    std::vector<DiskInfo> GetDiskInfo_win() {
        std::vector<DiskInfo> disks;
        // 获取所有逻辑驱动器
        char drives[256];
        if (GetLogicalDriveStringsA(256, drives)) {
            for (char *drive = drives; *drive; drive += strlen(drive) + 1) {
                if (GetDriveTypeA(drive) == DRIVE_FIXED) {
                    // 只处理固定磁盘
                    DiskInfo info;
                    info.drive = drive;

                    // 获取磁盘空间
                    ULARGE_INTEGER total, free;
                    if (GetDiskFreeSpaceExA(drive, nullptr, &total, &free)) {
                        info.total = total.QuadPart;
                        info.free = free.QuadPart;
                        disks.push_back(info);
                    }
                }
            }
        }
        return disks;
    }


    // 获取内存信息
    MemoryInfo GetMemoryInfo_win() {
        MemoryInfo info{};
        MEMORYSTATUSEX status;
        status.dwLength = sizeof(status);
        if (GlobalMemoryStatusEx(&status)) {
            info.total = status.ullTotalPhys;
            info.available = status.ullAvailPhys;
            info.usagePercent = status.dwMemoryLoad;
        }
        return info;
    }
}
