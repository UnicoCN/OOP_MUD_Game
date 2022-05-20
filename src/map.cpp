#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

#include "../include/map.h"
#include "../include/attributes.h"
#include "../include/IO.h"
#include "../include/start_menu.h"

extern start_menu Menu;
extern Attributes attr;
/*
    Check_Object
    -1 没有物品
    0 人
    1 灯
    2 怪
    3 门 
    4 梯
    （待添加）
*/

int Map::Check_Object(int x, int y) {
    if (x == this->people.first && y == this->people.second) return 0;
    for (auto p = this->light.begin(); p != this->light.end(); ++p)
        if (x == p->first && y == p->second) return 1;
    for (auto p = this->monster.begin(); p != this->monster.end(); ++p)
        if (x == p->first && y == p->second) return 2;
    for (auto p = this->door.begin(); p != this->door.end(); ++p)
        if (x == p->first && y == p->second) return 3;
    for (auto p = this->stair.begin(); p != this->stair.end(); ++p)
        if (x == p->first && y == p->second) return 4;
    return -1;
}

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
            int Tmp = Check_Object(i,j);
            if (Tmp == 1) {
                std::cout << "灯";
                del_block[i] ++;
            } else 
            if (Tmp == 2) {
                std::cout << "怪";
                del_block[i] ++;
            } else
            if (Tmp == 3) {
                std::cout << "门";
                del_block[i] ++;
            } else
            if (Tmp == 4) {
                std::cout << "梯";
                del_block[i] ++;
            } else 
            if (Tmp == 0) {
                std::cout << "人";
                del_block[i] ++;
            } else {
                if (j == width -1 - del_block[i]) {
                    std::cout << "|" << std::endl;
                    j = width;
                    continue;
                } else std::cout << " ";
            }
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
            int Tmp = Check_Object(i,j);
            if (Tmp == 1) {
                std::cout << "灯";
                del_block[i] ++;
            } else 
            if (Tmp == 2) {
                std::cout << "怪";
                del_block[i] ++;
            } else
            if (Tmp == 3) {
                std::cout << "门";
                del_block[i] ++;
            } else
            if (Tmp == 4) {
                std::cout << "梯";
                del_block[i] ++;
            } else 
            if (Tmp == 0) {
                std::cout << "人";
                del_block[i] ++;
            } else {
                if (j == width -1 - del_block[i]) {
                    std::cout << "|" << std::endl;
                    j = width;
                    continue;
                } else std::cout << " ";
            }
        }
    }
    for (int i = 0;  i < width; ++i)
        std::cout << "-";
    std::cout << std::endl;
}

void Map::Change_Human_Position(int dis)
{
    this->people.second += dis;
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
            case 27:
                IO io_save;
                io_save.write_map(*this);
                attr.write_attr();
                system("cls");
                Menu.Choose();
                break;
            default:
                this->Change_Human_Position(0);
                break;
            }
        }
    }
}