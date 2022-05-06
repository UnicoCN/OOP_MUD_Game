#include<iostream>
#include<windows.h>
#include<string>

#include "../include/attributes.h"

Attributes::Attributes() {
    Weapons_Num = 1;
    Props_Num = 1;
    Weapons[0] = "普通的木棍";
    Props[0] = "一把破旧的钥匙";
    Blood = 100;
    Starveness = 100;
    floor = 10;
}

void Attributes::Show_Blood() {
    SetConsoleOutputCP(65001);
    std::cout << "血量: " << Blood << std::endl; 
}

void Attributes::Show_Starveness() {
    SetConsoleOutputCP(65001);
    std::cout << "饥饿值: " << Starveness << std::endl; 
}

void Attributes::Show_Weapons() {
    SetConsoleOutputCP(65001);
    std::cout << "武器: ";
    for (int i = 0; i < Weapons_Num; ++i)
        std::cout << Weapons[i] << " ";
    std::cout << std::endl;
}

void Attributes::Show_Props() {
    SetConsoleOutputCP(65001);
    std::cout << "物品: ";
    for (int i = 0; i < Props_Num; ++i)
        std::cout << Props[i] << " ";
    std::cout << std::endl;
}

void Attributes::Show_Floor() {
    SetConsoleOutputCP(65001);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    std::cout << "当前楼层:" << floor << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

void Attributes::Change_Blood(int num) {

}

void Attributes::Change_Starveness(int num) {

}

void Attributes::Add_Weapons(std::string w, bool is_add) {

}

void Attributes::Add_Props(std::string w, bool is_add) {

}
