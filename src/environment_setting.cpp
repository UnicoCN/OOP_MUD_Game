#include <windows.h>
#include "../include/environment_setting.h"

void environment_setting()
{
    HANDLE handle;
    CONSOLE_CURSOR_INFO CursorInfo;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = false; //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
    SetConsoleOutputCP(65001);
    system("mode con cols=200 lines=200");
    return;
}