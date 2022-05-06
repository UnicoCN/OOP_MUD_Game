#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>

#include "../include/start_menu.h"

void start_menu::print_pic()
{
    std::ifstream test;
    test.open("pic.txt", std::ios::in);
    if(!test.is_open())
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
    SetConsoleOutputCP(65001);
    for(int i = 0; i < 4; ++i)
    {
        if(i == choice)
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
    COORD pos={0, 19};
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut,pos);
    print_menu();
    return;
}

int start_menu::dead_lock()
{
    system("mode con cols=200 lines=200");
    print_pic();
    print_menu();
    return input_check();
}

int start_menu::input_check()
{
    int ch;
    while(1)
    {
        if(_kbhit())
        {
            ch = _getch();
            switch(ch)
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
