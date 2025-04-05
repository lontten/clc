//
// Created by lontten on 2025/4/5.
//

#pragma once
#include <cstdio>


#if defined(_WIN32)


int pln() {
    printf("窗口 linux 未实现\n");
    return 0;
}
#endif

#if defined(__APPLE__)
int pln() {
    printf("窗口 linux 未实现\n");
    return 0;
}
#endif
