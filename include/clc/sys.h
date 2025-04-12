//
// Created by Lontten on 2025/4/2.
//
#pragma once
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

namespace clc {
    std::string formatBytes(long long bytes);

    /**
      * 系统电源状态标识 (符合 Win32 API 规范)
      *
      */
    enum class PowerStatus {
        Unknown = 0, // 状态未知或获取失败
        None = 1, // 无电池（BATTERY_FLAG_NO_BATTERY）
        Charging = 2, // 正在充电（AC在线 + BATTERY_FLAG_CHARGING）
        OnBattery = 3, // 使用电池供电（AC离线）
        LowBattery = 4, // 低电量警告（BATTERY_FLAG_LOW）
        CriticalBattery = 5, // 严重低电量（BATTERY_FLAG_CRITICAL）
        Overheated = 6, // 电池过热
        Fault = 7 // 电池故障
    };

    struct PowerInfo {
        int battery_percentage;
        PowerStatus power_status;

        // 带电池状态语义的字符串转换
        [[nodiscard]] std::string ToString() const {
            std::ostringstream oss;

            // 优先处理无电池状态
            if (power_status == PowerStatus::None) {
                oss << "[无电池设备]";
                return oss.str();
            }

            // 处理未知状态
            if (power_status == PowerStatus::Unknown) {
                oss << "未知状态（无法获取电源信息）";
                if (battery_percentage != -1) {
                    oss << "，原始电量值: " << battery_percentage;
                }
                return oss.str();
            }

            // 构建状态描述
            switch (power_status) {
                case PowerStatus::Charging:
                    oss << "充电中";
                    break;
                case PowerStatus::OnBattery:
                    oss << "使用电池";
                    break;
                case PowerStatus::LowBattery:
                    oss << "低电量警告";
                    break;
                case PowerStatus::CriticalBattery:
                    oss << "严重低电量";
                    break;
                default:
                    oss << "未定义状态";
            }

            // 附加电量百分比
            if (battery_percentage == -1) {
                oss << "（电量未知）";
            } else if (battery_percentage == 0 && power_status != PowerStatus::None) {
                oss << "（电量耗尽）"; // 仅在电池存在时显示0%
            } else {
                oss << " (" << battery_percentage << "%)";
            }

            // 特殊状态组合检查
            if (power_status == PowerStatus::OnBattery && battery_percentage == 100) {
                oss << " [已充满]";
            }

            return oss.str();
        }
    };


    struct SystemInfo {
        std::string name;
        std::string version;
        std::string build;
        std::string arch;
        std::string language;
        std::string country;
        std::string timezone;
        std::string time;
        std::string date;
        std::string uptime;
        std::string hostname;
        std::string username;
        std::string domain;
        std::string ip;
        std::string mac;
        std::string mac_vendor;
        std::string mac_vendor_url;
    };

    PowerInfo powerStatus();


    // 硬盘信息结构体
    struct DiskInfo {
        std::string drive; // 盘符（如 "C:"）
        long long total; // 总空间（字节）
        long long free; // 可用空间（字节）
        [[nodiscard]] long long used() const { return total - free; } // 计算已用空间
        [[nodiscard]] std::string ToString() const {
            std::ostringstream oss;
            oss << "盘符: " << drive
                    << "\n总空间: " << formatBytes(total)
                    << "\n已用空间: " << formatBytes(used())
                    << "\n可用空间: " << formatBytes(free) << " ";
            return oss.str();
        }
    };

    std::vector<DiskInfo> GetDiskInfo();

    // 内存信息结构体
    struct MemoryInfo {
        long long total; // 总物理内存（字节）
        long long available; // 可用物理内存（字节）
        int usagePercent; // 已用内存百分比

        [[nodiscard]] std::string ToString() const {
            std::ostringstream oss;
            oss << "总内存: " << formatBytes(total)
                    << "\n可用内存: " << formatBytes(available)
                    << "\n使用率: " << usagePercent << "%";
            return oss.str();
        }
    };

    MemoryInfo GetMemoryInfo();


    // CPU使用率结构体
    struct CpuUsage {
        double total; // 总CPU使用率（百分比）
        std::vector<double> cores; // 各核心使用率
    };
}
