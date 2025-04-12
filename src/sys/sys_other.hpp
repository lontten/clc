//
// Created by lontten on 2025/4/5.
//

#pragma once
#include <cstdio>

namespace clc::platform {
   PowerInfo powerStatus_other() {
        printf("未知平台\n");
        return PowerInfo();
    }
}
