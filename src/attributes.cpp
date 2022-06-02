#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

#include "../include/environment_setting.h"
#include "../include/attributes.h"

Attributes::Attributes()
{
    Weapons_Num = 1;
    Props_Num = 1;
    Weapons[0] = "普通的木棍";
    Props[0] = "一把破旧的钥匙";
    Blood = 100;
    Starveness = 100;
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
    std::cout << "物品: ";
    for (int i = 0; i < Props_Num; ++i)
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

void Attributes::Change_Blood(int num)
{
    this->Blood += num;
}

void Attributes::Change_Starveness(int num)
{
    this->Starveness += num;
}

void Attributes::Add_Weapons(std::string w, bool is_add)
{
}

void Attributes::Add_Props(std::string w, bool is_add)
{
}


bool Attributes::read_attr(int option) {
    std::ifstream in_stream;
    std::string file_name;
    if (option == 1) file_name = ".\\save\\save_attr.txt";
        else if (option == 0) file_name = ".\\new\\new_attr.txt";
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

bool Attributes::write_attr(int option) {
    std::ofstream out_stream;
    std::string file_name;
    if (option == 1) file_name = ".\\save\\save_attr.txt";
        else if (option == 0) file_name = ".\\new\\new_attr.txt";
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
