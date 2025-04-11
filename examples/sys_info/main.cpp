//
// Created by Lontten on 2025/4/2.
//
#include <format>
#include <iostream>
#include <windows.h>
// 全局变量存储电量信息
std::string g_szBatteryInfo = "正在获取电量...";

void GetBatteryStatus();

int main() {
    GetBatteryStatus();
    std::cout << g_szBatteryInfo << std::endl;
    return 0;
}


// 获取电池状态的函数
void GetBatteryStatus() {
    SYSTEM_POWER_STATUS status;
    if (!GetSystemPowerStatus(&status)) {
        g_szBatteryInfo = "获取电量失败";
        return;
    }
    if (status.BatteryFlag == 128) {
        g_szBatteryInfo = "计算机没有电池";
    } else if (status.BatteryFlag & 8) {
        g_szBatteryInfo = std::format("电量：{}% (正在充电)", status.BatteryLifePercent);
    } else {
        g_szBatteryInfo = std::format("电量：{}%", status.BatteryLifePercent);
    }
}
