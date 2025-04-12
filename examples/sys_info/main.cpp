//
// Created by Lontten on 2025/4/12.
//
#include <format>
#include <iostream>
#include <clc/sys.h>


int main() {
    const auto status = clc::powerStatus();
    std::cout << status.ToString() << std::endl;

    for (const auto &disk: clc::GetDiskInfo()) {
        std::cout << disk.ToString() << std::endl;
    }
    std::cout << clc::GetMemoryInfo().ToString() << std::endl;
    return 0;
}
