//
// Created by Lontten on 2025/4/2.
//
#include <clc/win.h>
#include <clc/message.h>

int main() {
    // clc::win("一个clc 空白窗口");
    message("标题", "内容", clc::MessageType::Ok, 0, clc::LangType::ENGLISH_US);
    return 0;
}
