#include "../include/about_us.h"
#include "../include/environment_setting.h"
#include "../include/start_menu.h"

#include<iostream>
#include<string>
#include<conio.h>

extern start_menu Menu;

void About_US::Show() {
    environment_setting();
    std::string lots_of_tab = "                                                ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << lots_of_tab << " " << lots_of_tab << "关于我们" << std::endl;
    std::cout << std::endl;
    std::cout << lots_of_tab << "                   本次我们组选择的题目是制作一个 MUD(Multiple User Domain)游戏。" << std::endl;
    std::cout << std::endl;
    std::cout << lots_of_tab << "                            游戏名称为 One Way Out(逃出生天),是一款逃生类 MUD 游戏。" << std::endl;
    std::cout << std::endl;
    std::cout << lots_of_tab << "                               玩家通过操控角色进行逃生，最终逃出生天。" << std::endl;
    std::cout << std::endl;
    std::cout << lots_of_tab << "                          游戏主要借鉴了一款比较经典的 2D 生存类游戏 SKY HILL。" << std::endl;
    std::cout << std::endl;
    std::cout << "                                 " << "我们十分欣赏这款游戏的剧情和玩法,并且认为 MUD 游戏可以很好地还原这款游戏的核心玩法以及加入我们个人的一些理解，成就一款既有意思又有深度的游戏。" << std::endl;
    std::cout << std::endl;
    std::cout << lots_of_tab << "                                       作者: 胡嘉成     陈佳彤" << std::endl;
    this->Wait_Input();
}

void About_US::Wait_Input() {
    int ch;
    while(1)
    {
        if(_kbhit())
        {
            ch = _getch();
            switch(ch)
            {
                case 27:
                    system("cls");
                    Menu.Choose();
                    break;
                default:
                    std::cout << "Please Press Esc to return QwQ" << std::endl;
                    break;
            }
        }
    }
}