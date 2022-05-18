#include "include/start_menu.h"
#include "include/attributes.h"
#include "include/map.h"
#include "include/IO.h"

#include <windows.h>

int main() {
    start_menu Menu;
    HANDLE handle;
    CONSOLE_CURSOR_INFO CursorInfo;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = false; //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
    int choice = Menu.dead_lock();
    if (choice == 0) {
        system("cls");
        Attributes attr;
        attr.Show_Blood();
        attr.Show_Starveness();
        attr.Show_Weapons();
        attr.Show_Props();
        Map m;
        m.Show_Floor();
        m.Draw_Map();
        m.Listen_Keyboard();
    }
    else if(choice == 1)
    {
        IO read;
        map_data test;
        test.floor = 7;
        read.read_map(test);
        system("cls");
        auto it = test.light.begin();
        for(; it != test.light.end(); it++)
            printf("%d %d\n", (*it).first, (*it).second);
        while(1);
    }
    return 0;
}