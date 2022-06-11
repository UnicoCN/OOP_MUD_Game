#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

#include "../include/environment_setting.h"
#include "../include/attributes.h"
#include "../include/IO.h"
#include "../include/YouDead.h"

extern Map m;
extern Attributes attr;

Attributes::Attributes()
{
    Weapons_Num = 1;
    Props_Num = 1;
    Weapons.push_back("普通的木棍");
    Props.push_back("一把破旧的钥匙");
    Blood = 100;
    Starveness = 100;
    Attack = 10;
    San = 100;
}

void Attributes::Show_Blood()
{
    SetConsoleOutputCP(65001);
    std::cout << "血量: " << Blood << std::endl;
}

void Attributes::Show_Starveness()
{
    SetConsoleOutputCP(65001);
    std::cout << "饥饿值: " << Starveness << std::endl;
}

void Attributes::Show_Weapons()
{
    SetConsoleOutputCP(65001);
    std::cout << "武器: ";
    for (int i = 0; i < Weapons_Num; ++i)
        std::cout << Weapons[i] << " ";
    std::cout << std::endl;
}

void Attributes::Show_Props()
{
    SetConsoleOutputCP(65001);
    std::cout << "物品: （按e键可以打开背包并使用物品）";
    for (int i = 0; i < Props.size(); ++i)
        std::cout << Props[i] << " ";
    std::cout << std::endl;
}

void Attributes::Show_All()
{
    this->Show_Blood();
    this->Show_Starveness();
    this->Show_Weapons();
    this->Show_Props();
}

void Attributes::Re_Show_All()
{
    HANDLE hOut;
    COORD pos = {0, 0};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
    std::string blank = "";
    for (int i = 0; i < 150; ++i)
        blank += " ";
    std::cout << blank << std::endl;
    std::cout << blank << std::endl;
    std::cout << blank << std::endl;
    std::cout << blank << std::endl;
    pos = {0, 0};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
    Show_All();
}

void Attributes::Change_Blood(int num)
{
    if (num < 0)
    {
        if (this->Blood <= abs(num))
        {
            this->Blood = 0;
            YouDead();
            attr.read_attr(0);
            attr.Show_All();
            IO io_ini;
            m.floor = 7;
            io_ini.read_map(m, 0);
            m.Show_Floor();
            m.Draw_Map();
            m.Listen_Keyboard();
        }
        else
            this->Blood += num;
    }
    else
        this->Blood += num;
}

void Attributes::Change_Starveness(int num)
{
    if (num < 0)
    {
        if (this->Starveness < abs(num))
        {
            this->Starveness = 0;
            Change_Blood(-10);
        }
        else
            this->Starveness += num;
    }
    else
        this->Starveness += num;
}

void Attributes::Change_San(int num)
{
    San += num;
}

void Attributes::openbag()
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 20};
    SetConsoleCursorPosition(hOut, pos);
    std::cout << "看看我还有些什么……" << std::endl;
    for (int i = 0; i < Props.size(); ++i)
    {
        COORD pos = {0, (short)(21 + i)};
        SetConsoleCursorPosition(hOut, pos);
        std::cout << "[" << i << "] " << Props[i] << std::endl;
    }
    std::cout << "你觉得我可以用些什么？" << std::endl;
    int choice;
    std::cin >> choice;
    if (choice >= 0 && choice < Props.size())
    {
        use_prop(choice);
        Sleep(1000);
        closebag();
    }
    else
    {
        std::cout << "那就留到下次吧" << std::endl;
        Sleep(1000);
        closebag();
    }
    return;
}

void Attributes::use_prop(int choice)
{
    std::string target = Props[choice];
    for(auto it = Props.begin(); it != Props.end(); ++it)
    {
        if((*it) == target)
        {
            Props.erase(it);
            break;
        }
    }
    if (target == "怪物肉")
    {
        Change_Starveness(30);
        Change_Blood(20);
        Change_San(-20);
        std::cout << "我想，紧急情况下，这个也能顶饿吧……" << std::endl;
    }
    else if (target == "苹果")
    {
        Change_Starveness(20);
        Change_Blood(10);
        Change_San(20);
        std::cout << "很甜，就是太少了" << std::endl;
    }
    else if (target == "罐头")
    {
        Change_Starveness(40);
        Change_San(10);
        std::cout << "我想这件事之后，我会在家里多囤几箱……" << std::endl;
    }
    else if (target == "军用干粮")
    {
        Change_Starveness(100);
        Change_San(20);
        std::cout << "虽然味道不怎么样，但真的很饱！" << std::endl;
    }
    else if (target == "急救包")
    {
        Change_Blood(80);
        Change_San(20);
        std::cout << "我觉得，它能把我从地狱里拉出来。无论是这里还是真正的地狱。" << std::endl;
    }
    else if (target == "纱布")
    {
        Change_Blood(30);
        Change_San(20);
        std::cout << "难以致信，那群怪物竟然还能留下干净的纱布！" << std::endl;
    }
    else if(target == "止痛药")
    {
        Change_Blood(30);
        Change_San(-20);
        std::cout << "我感觉……没有那么痛了" << std::endl;
    }
    else
    {
        std::cout << "呃……我暂时还没想到怎么用这个，下次再说吧。" << std::endl;
    }
    Re_Show_All();
    return;
}

void Attributes::closebag()
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < Props.size() + 10; ++i)
    {
        COORD pos = {0, (short)(20 + i)};
        SetConsoleCursorPosition(hOut, pos);
        std::cout << "                                                                      " << std::endl;
    }
    return;
}

void Attributes::Add_Weapons(std::string w, bool is_add)
{
    char choice;
    if (Weapons_Num < Max_Weapon)
    {
        Weapons_Num++;
        Weapons.push_back(w);
        Attack = SwitchWeaponToAttack(w);
    }
    else
    {
        HANDLE hOut;
        COORD pos = {0, 13};
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hOut, pos);
        std::cout << "我没必要带这么多武器，应该丢掉哪一把？" << std::endl;
        std::cout << "[0] " << w << std::endl;
        std::cout << "[1] " << Weapons[0] << std::endl;
        while (1)
        {
            choice = getchar();
            if (choice == '0')
                break;
            else if (choice == '1')
            {
                Weapons.pop_back();
                Weapons.push_back(w);
                Attack = SwitchWeaponToAttack(w);
                break;
            }
        }
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hOut, pos);
        std::cout << "                                      " << std::endl;
        std::cout << "                                      " << std::endl;
        std::cout << "                                      " << std::endl;
        std::cout << "                                      " << std::endl;
    }
    return;
}

void Attributes::Add_Props(std::string w, bool is_add)
{
    if (Props_Num < Max_Props)
    {
        Props_Num++;
        Props.push_back(w);
    }
}

bool Attributes::read_attr(int option)
{
    std::ifstream in_stream;
    std::string file_name;
    if (option == 1)
        file_name = ".\\save\\save_attr.txt";
    else if (option == 0)
        file_name = ".\\new\\new_attr.txt";
    in_stream.open(file_name);
    if (!in_stream)
        return false;
    else
    {
        std::string type;
        unsigned long _Blood;
        unsigned long _Starveness;
        std::string _Weapons;
        std::string _Props;
        Weapons_Num = 0;
        Props_Num = 0;
        while (in_stream >> type)
        {
            if (type == "Blood:")
            {
                in_stream >> _Blood;
                this->Blood = _Blood;
                continue;
            }

            if (type == "Starveness:")
            {
                in_stream >> _Starveness;
                this->Starveness = _Starveness;
                continue;
            }

            if (type == "Weapons:")
            {
                while (1)
                {
                    in_stream >> _Weapons;
                    if (_Weapons == "###")
                        break;
                    Weapons_Num++;
                    Weapons[Weapons_Num - 1] = _Weapons;
                }
                continue;
            }

            if (type == "Props:")
            {
                while (1)
                {
                    in_stream >> _Props;
                    if (_Props == "###")
                        break;
                    Props_Num++;
                    Props[Props_Num - 1] = _Props;
                }
                continue;
            }
        }
        return true;
    }
}

bool Attributes::write_attr(int option)
{
    std::ofstream out_stream;
    std::string file_name;
    if (option == 1)
        file_name = ".\\save\\save_attr.txt";
    else if (option == 0)
        file_name = ".\\new\\new_attr.txt";
    out_stream.open(file_name);
    if (!out_stream)
        return false;
    else
    {
        environment_setting();
        out_stream << "Blood:" << std::endl;
        out_stream << Blood << std::endl;
        out_stream << "Starveness:" << std::endl;
        out_stream << Starveness << std::endl;
        out_stream << "Weapons:" << std::endl;
        for (int i = 0; i < Weapons_Num; ++i)
            out_stream << Weapons[i] << std::endl;
        out_stream << "###" << std::endl;
        out_stream << "Props:" << std::endl;
        for (int i = 0; i < Props_Num; ++i)
            out_stream << Props[i] << std::endl;
        out_stream << "###" << std::endl;
        out_stream.close();
        return true;
    }
}

unsigned long Attributes::SwitchWeaponToAttack(std::string w)
{
    std::string oxe = "消防斧";
    std::string knife = "水果刀";
    std::string bang = "普通的木棍";
    if (w == oxe)
        return 30;
    else if (w == knife)
        return 20;
    else if (w == bang)
        return 15;
    else
        return 10;
}

unsigned long Attributes::Get_Attack()
{
    return Attack;
}

int Attributes::Get_San()
{
    return San;
}