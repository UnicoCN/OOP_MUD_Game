#ifndef _START_GAME_H
#define _START_GAME_H

#include<string>
#include<stdbool.h>
#include<vector>
#include<stdio.h>

#define Max_Weapon 1
#define Max_Props 10


class Attributes {
private:
    unsigned long Weapons_Num; // 武器数量
    unsigned long Props_Num; // 道具数量
    std::vector<std::string> Weapons; // 武器
    std::vector<std::string> Props;// 道具
    unsigned long Blood; // 血量
    unsigned long Starveness; // 饥饿值
    unsigned long Attack;
    int San;
    unsigned long SwitchWeaponToAttack(std::string w);
    void use_prop(int choice);
    
public:
    Attributes (); // 构造函数
    void Show_Blood(); // 显示血量
    void Show_Starveness(); // 显示饥饿值
    void Show_Weapons(); // 显示武器
    void Show_Props(); // 显示道具
    void Show_All();
    void Re_Show_All();
    unsigned long Get_Attack();
    int Get_San();
    void Add_Weapons(std::string w, bool is_add); // 修改武器
    void Add_Props(std::string w, bool is_add); // 修改道具
    void Change_Blood(int num); // 更改血量
    void Change_Starveness(int num); // 更改饥饿值
    void Change_San(int num);
    bool read_attr(int option);
    bool write_attr(int option);
    void openbag();
    void closebag();
};

#endif