#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

#include "../include/map.h"
#include "../include/attributes.h"

void Map::Show_Floor()
{
    SetConsoleOutputCP(65001);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    std::cout << "当前楼层:" << floor << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

void Map::Draw_Map()
{
    SetConsoleOutputCP(65001); // 修改中文编码格式
    for (int i = 0; i < width; ++i)
        std::cout << "-";
    std::cout << std::endl;
    int del_block[5]; // 处理中文的字节占用问题
    memset(del_block, 0, sizeof(del_block));
    for (int i = height - 1; i >= 0; --i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (j == human_x && i == human_y)
            {
                del_block[i]++;
                std::cout << "人";
                continue;
            }
            if (j == light_x && i == light_y)
            {
                del_block[i]++;
                std::cout << "灯";
                continue;
            }
            if (j == monster_x && i == monster_y)
            {
                del_block[i]++;
                std::cout << "怪";
                continue;
            }
            if (j == door_x && i == door_y)
            {
                del_block[i]++;
                std::cout << "门";
                continue;
            }
            if (j == stairs_x && i == stairs_y)
            {
                del_block[i]++;
                std::cout << "梯";
                continue;
            }
            if (j == width - 1 - del_block[i])
            {
                std::cout << "|" << std::endl;
                j = width;
                continue;
            }
            std::cout << " ";
        }
    }
    for (int i = 0; i < width; ++i)
        std::cout << "-";
    std::cout << std::endl;
}

void Map::Update_Map() {
    HANDLE hOut;
    HANDLE handle;
    COORD pos={0, 10};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut,pos);
    int del_block[5];// 处理中文的字节占用问题
    memset(del_block,0,sizeof(del_block));
    for (int i = 0; i >= 0; --i) {
        for (int j = 0; j < width; ++j) {
            if (j == human_x && i == human_y) {
                del_block[i] ++;
                std::cout << "人";
                continue;
            } 
            if (j == light_x && i ==  light_y) {
                del_block[i] ++;
                std::cout << "灯";
                continue;
            }
            if (j == monster_x && i == monster_y) {
                del_block[i] ++;
                std::cout << "怪";
                continue;
            }
            if (j == door_x && i == door_y) {
                del_block[i] ++;
                std::cout << "门";
                continue;
            }
            if (j == stairs_x && i == stairs_y) {
                del_block[i] ++;
                std::cout << "梯";
                continue;
            }
            if (j == width -1 - del_block[i]) {
                std::cout << "|" << std::endl;
                j = width;
                continue;
            }
            std::cout << " ";
        }
    }
    for (int i = 0;  i < width; ++i)
        std::cout << "-";
    std::cout << std::endl;
}

void Map::Change_Human_Position(int dis)
{
    human_x += dis;
    this->Update_Map();
}

void Map::Listen_Keyboard()
{
    int ch;
    while (1)
    {
        if (_kbhit())
        {
            ch = _getch();
            switch (ch)
            {
            case 75:
                this->Change_Human_Position(-1);
                break;
            case 77:
                this->Change_Human_Position(1);
                break;
            default:
                this->Change_Human_Position(0);
                break;
            }
        }
    }
}