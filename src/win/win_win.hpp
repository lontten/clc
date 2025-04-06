//
// Created by lontten on 2025/4/5.
//

#pragma once

// 强制启用Unicode编码（现代Windows开发必备）
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>  // 包含Windows API核心头文件

/* 窗口过程函数声明
 * hwnd    : 窗口句柄
 * uMsg    : 消息类型（如鼠标点击、键盘输入等）
 * wParam  : 消息附加参数（类型取决于uMsg）
 * lParam  : 消息附加参数（类型取决于uMsg） */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

/* Windows程序入口点（Unicode版本）
 * hInstance      : 当前程序实例句柄
 * hPrevInstance  : 旧版Windows遗留参数（始终为NULL）
 * pCmdLine       : 命令行参数字符串
 * nCmdShow       : 窗口初始显示方式（如最大化/最小化） */
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow) {
    // ================== 1. 注册窗口类 ==================
    const wchar_t CLASS_NAME[] = L"BlankWindowClass"; // 窗口类唯一标识

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc; // 设置消息处理回调函数
    wc.hInstance = hInstance; // 绑定当前实例
    wc.lpszClassName = CLASS_NAME; // 指定类名称
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1); // 窗口背景色（系统默认白色）
    wc.style = CS_HREDRAW | CS_VREDRAW; // 窗口尺寸变化时重绘

    // 注册窗口类（失败则弹出错误框）
    if (!RegisterClass(&wc)) {
        MessageBox(nullptr, L"窗口类注册失败", L"致命错误", MB_ICONERROR | MB_OK);
        return 1;
    }

    // ================== 2. 创建窗口实例 ==================
    HWND hwnd = CreateWindowEx(
        0, // 扩展样式（无特殊需求）
        CLASS_NAME, // 已注册的窗口类名
        L"空白窗口示例", // 标题栏文字
        WS_OVERLAPPEDWINDOW, // 标准窗口样式（含标题栏/缩放按钮等）

        // 初始位置和尺寸（使用系统默认值）
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600, // 窗口初始宽度和高度

        nullptr, // 父窗口句柄（无父窗口）
        nullptr, // 菜单句柄（无菜单）
        hInstance, // 程序实例句柄
        nullptr // 创建参数（无额外数据）
    );

    // 检查窗口创建是否成功
    if (hwnd == nullptr) {
        MessageBox(nullptr, L"窗口创建失败", L"致命错误", MB_ICONERROR | MB_OK);
        return 1;
    }

    // ================== 3. 显示与更新窗口 ==================
    ShowWindow(hwnd, nCmdShow); // 根据启动参数显示窗口
    UpdateWindow(hwnd); // 强制立即重绘窗口

    // ================== 4. 消息处理循环 ==================
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        // 持续获取消息
        TranslateMessage(&msg); // 转换键盘消息
        DispatchMessage(&msg); // 分发到窗口过程
    }

    return 0;
}

/* 窗口过程具体实现（处理所有窗口消息） */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg,
                            WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        // ========== 窗口销毁事件 ==========
        case WM_DESTROY:
            PostQuitMessage(0); // 发送退出消息，结束消息循环
            return 0;

        // ========== 窗口绘制事件 ==========
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps); // 获取绘图设备上下文

            /* 使用系统背景色填充客户区
             * hdc        : 绘图设备上下文
             * ps.rcPaint : 需要重绘的区域
             * COLOR_WINDOW+1 : 系统默认窗口背景画刷 */
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));

            EndPaint(hwnd, &ps); // 结束绘制操作
            return 0;
        }

        // ========== 其他未处理消息 ==========
        default:
            /* 将未处理消息交给系统默认处理
             * 必须调用此函数保证窗口基本功能正常 */
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

namespace clc {
    int win_win() {
        // 获取当前实例句柄
        HINSTANCE hInstance = GetModuleHandle(nullptr);

        // 获取命令行参数（Unicode 格式）
        PWSTR pCmdLine = GetCommandLineW();

        // 调用 wWinMain
        return wWinMain(hInstance, nullptr, pCmdLine, SW_SHOW);
    }
}
