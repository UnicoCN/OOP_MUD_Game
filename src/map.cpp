#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

#include "../include/map.h"
#include "../include/attributes.h"
#include "../include/IO.h"
#include "../include/start_menu.h"
#include "../include/interact.h"

extern start_menu Menu;
extern Attributes attr;
extern interact inter;
/*
    Check_Object
    -1 没有物品
    0 人
    1 灯
    2 怪
    3 门
    4 梯
*/

// 1 代表 与灯重合
// 2 代表 与怪重合
// 3 代表 与门重合
// 4 代表 与梯子重合
int collide;
bool bag_open = false;

int Map::Check_Object(int x, int y)
{
    bool flag_0 = false;
    bool flag_1 = false;
    bool flag_2 = false;
    bool flag_3 = false;
    bool flag_4 = false;
    collide = -1;
    if (x == this->people.first && y == this->people.second)
        flag_0 = true;
    for (auto p = this->light.begin(); p != this->light.end(); ++p)
        if (x == p->first && y == p->second)
            flag_1 = true;
    for (int i = 0; i < this->monster.size(); ++i)
        if (x == monster[i].first && y == monster[i].second && monster_flag[i])
            flag_2 = true;
    for (int i = 0; i < this->door.size(); ++i)
        if (x == door[i].first && y == door[i].second)
            flag_3 = true;
    for (auto p = this->stair.begin(); p != this->stair.end(); ++p)
        if (x == p->first && y == p->second)
            flag_4 = true;

    if (flag_0 && flag_1)
        collide = 1;
    else if (flag_0 && flag_2)
        collide = 2;
    else if (flag_0 && flag_3)
        collide = 3;
    else if (flag_0 && flag_4)
        collide = 4;
    if (flag_0)
        return 0;
    else if (flag_1)
        return 1;
    else if (flag_2)
        return 2;
    else if (flag_3)
        return 3;
    else if (flag_4)
        return 4;
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
            int Tmp = Check_Object(i, j);
            if (Tmp == 1)
            {
                std::cout << "灯";
                del_block[i]++;
            }
            else if (Tmp == 2)
            {
                std::cout << "怪";
                del_block[i]++;
            }
            else if (Tmp == 3)
            {
                std::cout << "门";
                del_block[i]++;
            }
            else if (Tmp == 4)
            {
                std::cout << "梯";
                del_block[i]++;
            }
            else if (Tmp == 0)
            {
                std::cout << "人";
                del_block[i]++;
            }
            else
            {
                if (j == width - 1 - del_block[i])
                {
                    std::cout << "|" << std::endl;
                    j = width;
                    continue;
                }
                else
                    std::cout << " ";
            }
        }
    }
    for (int i = 0; i < width; ++i)
        std::cout << "-";
    std::cout << std::endl;
}

void Map::Update_Map()
{
    HANDLE hOut;
    HANDLE handle;
    COORD pos = {0, 10};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
    int del_block[5]; // 处理中文的字节占用问题
    memset(del_block, 0, sizeof(del_block));
    int tmp_block = 0;
    for (int i = 0; i >= 0; --i)
    {
        for (int j = 0; j < width; ++j)
        {
            int Tmp = Check_Object(i, j);
            if (Tmp == 1)
            {
                std::cout << "灯";
                del_block[i]++;
            }
            else if (Tmp == 2)
            {
                std::cout << "怪";
                del_block[i]++;
            }
            else if (Tmp == 3)
            {
                std::cout << "门";
                del_block[i]++;
            }
            else if (Tmp == 4)
            {
                std::cout << "梯";
                del_block[i]++;
            }
            else if (Tmp == 0)
            {
                std::cout << "人";
                if (collide != -1)
                {
                    std::cout << " ";
                    tmp_block = 1;
                }
                del_block[i]++;
            }
            else
            {
                if (j == width - 1 - del_block[i] - tmp_block)
                {
                    std::cout << "|" << std::endl;
                    j = width;
                    continue;
                }
                else
                    std::cout << " ";
            }
        }
    }
    for (int i = 0; i < width; ++i)
        std::cout << "-";
    std::cout << std::endl;
    Check_Object(this->people.first, this->people.second);
    switch (collide)
    {
    case 1:
        std::cout << "你咋不上天呢？" << std::endl;
        break;
    case 2:
        std::cout << "看来，只能和它打一架了……" << std::endl;
        std::cout << "杀了它，能不能让“它”同样感到恐惧？" << std::endl;
        inter.start_interact(2, 0);
        for (int i = 0; i < monster.size(); ++i)
            if (people.first == monster[i].first && people.second == monster[i].second)
                monster_flag[i] = 0;
        Sleep(500);
        break;
    case 3:
        std::cout << "要进去看看吗？（按下回车键进行交互）" << std::endl;
        break;
    case 4:
        std::cout << "往上还是往下？还是···留在这里？（按下j选择下楼，k选择上楼）" << std::endl;
        break;
    default:
        std::cout << "                                                                  " << std::endl;
        std::cout << "                                                                  " << std::endl;
        std::cout << "                                                                  " << std::endl;
        std::cout << "                                                                  " << std::endl;
        std::cout << "                                                                  " << std::endl;
        std::cout << "                                                                  " << std::endl;
        std::cout << "                                                                  " << std::endl;
        std::cout << "                                                                  " << std::endl;
        break;
    }
}

void Map::Change_Human_Position(int dis)
{
    if (this->people.second + dis < width - 5 && this->people.second + dis > 0)
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
                case 101:
                    attr.openbag();
                    break;
                
                case 106:
                    if (collide == 4)
                        inter.start_interact(collide, 1);
                    break;
                case 107:
                    if (collide == 4)
                        inter.start_interact(collide, 0);
                    break;
                case 13:
                    if (collide == 3)
                    {
                        for (int i = 0; i < door.size(); ++i)
                            if (people.first == door[i].first && people.second == door[i].second && door_flag[i])
                            {
                                inter.start_interact(3, 0);
                                door_flag[i] = 0;
                                break;
                            }
                            else if(people.first == door[i].first && people.second == door[i].second && !door_flag[i])
                            {
                                std::cout << "这里我来过了吧，我想没有再进去的必要了……" << std::endl;
                                break;
                            }
                    }
                    break;
                case 75:
                    this->Change_Human_Position(-1);
                    break;
                case 77:
                    this->Change_Human_Position(1);
                    break;
                case 27:
                    IO io_save;
                    io_save.write_map(*this, 1);
                    attr.write_attr(1);
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