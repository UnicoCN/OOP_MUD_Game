#include <windows.h>
#include "../include/environment_setting.h"

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible=FALSE;
    cursor.dwSize=sizeof(cursor);
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle,&cursor);
}

void environment_setting()
{
    HANDLE handle;
    CONSOLE_CURSOR_INFO CursorInfo;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = false; //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
    HideCursor();
    SetConsoleOutputCP(65001);
    system("mode con cols=200 lines=200");
    return;
}