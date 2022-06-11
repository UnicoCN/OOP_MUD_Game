#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>

#include "../include/start_menu.h"
#include "../include/attributes.h"
#include "../include/IO.h"
#include "../include/map.h"
#include "../include/about_us.h"

extern Map m;
extern About_US as;
extern Attributes attr;

void start_menu::print_pic()
{
    std::ifstream test;
    test.open(".\\pic\\pic.txt", std::ios::in);
    if (!test.is_open())
        std::cout << "ERROR!" << std::endl;
    else
    {
        std::string line;
        while (getline(test, line))
            std::cout << line << std::endl;
    }
    test.close();
    return;
}

void start_menu::print_menu()
{
    for (int i = 0; i < 4; ++i)
    {
        if (i == choice)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        std::cout << lots_of_tab << menu[i] << std::endl;
        std::cout << "\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    }
    return;
}

void start_menu::reprint_menu()
{
    HANDLE hOut;
    COORD pos = {0, 19};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
    print_menu();
    return;
}

int start_menu::dead_lock()
{
    print_pic();
    print_menu();
    return input_check();
}

int start_menu::input_check()
{
    int ch;
    while (1)
    {
        if (_kbhit())
        {
            ch = _getch();
            switch (ch)
            {
            case 13:
                std::cout << "Confirm choice" << std::endl;
                return choice;
            case 72:
                choice = (choice + 3) % 4;
                reprint_menu();
                break;
            case 80:
                choice = (choice + 5) % 4;
                reprint_menu();
                break;
            default:
                break;
            }
        }
    }
}

void start_menu::Choose()
{
    int choice = this->dead_lock();
    if (choice == 0)
    {
        GameStart();
        system("cls");
        attr.read_attr(0);
        attr.Show_All();
        IO io_ini;
        io_ini.read_map(m, 0);
        m.Show_Floor();
        m.Draw_Map();
        m.Listen_Keyboard();
    }
    else if (choice == 1)
    {
        system("cls");
        attr.read_attr(1);
        attr.Show_All();
        IO io_continue;
        io_continue.read_map(m, 1);
        m.Show_Floor();
        m.Draw_Map();
        m.Listen_Keyboard();
    }
    else if (choice == 2)
    {
        as.Show();
    }
    else if (choice == 3)
    {
        exit(0);
    }
}

void start_menu::GameStart()
{
    system("cls");
    std::cout << "欢迎入住天堂酒店！" << std::endl;
    Sleep(1000);
    std::cout << "在离开那里之后，梦魇一直折磨着你……" << std::endl;
    Sleep(1000);
    std::cout << "银行卡上夸张的数字提醒着你，那不是一场梦，而是真实发生过的事情……" << std::endl;
    Sleep(1000);
    std::cout << "你决定换个环境，于是来到了这个风景如画的小岛上度假。" << std::endl;
    Sleep(1000);
    std::cout << "你斥巨资在岛上最好的天堂酒店订下了房间，准备享受你的假期。" << std::endl;
    Sleep(1000);
    std::cout << "“欢迎光临”" << std::endl;
    Sleep(1000);
    std::cout << "你从前台手中接过了房卡，住进了顶层的总统套房。" << std::endl;
    Sleep(1000);
    std::cout << "疲倦的你倒在床上沉沉睡去。" << std::endl;
    Sleep(1000);
    std::cout << "梦中，你又回到了那里，它扼住你的喉咙，对你说“欢迎入住，天堂酒店！”" << std::endl;
    Sleep(1000);
    std::cout << "你一身冷汗，从梦中惊醒，才意识到你已经从那里逃了出来，这只不过是一场梦。" << std::endl;
    Sleep(1000);
    std::cout << "……如果门外的前台不用它的声音说“欢迎，入住，天堂，酒店”…………就好了…………" << std::endl;
    Sleep(1000);
    std::cout << "请按回车开始游戏" << std::endl;
    getchar();
}