#ifndef _START_GAME_H
#define _START_GAME_H

#include<string>
#include<stdbool.h>

#define Max_Weapon 10
#define Max_Props 10


class Attributes {
private:
    unsigned long Weapons_Num; // 武器数量
    unsigned long Props_Num; // 道具数量
    std::string Weapons[Max_Weapon]; // 武器
    std::string Props[Max_Props];// 道具
    unsigned long Blood; // 血量
    unsigned long Starveness; // 饥饿值
    
public:
    Attributes (); // 构造函数
    void Show_Blood(); // 显示血量
    void Show_Starveness(); // 显示饥饿值
    void Show_Weapons(); // 显示武器
    void Show_Props(); // 显示道具
    void Show_All();
    void Add_Weapons(std::string w, bool is_add); // 修改武器
    void Add_Props(std::string w, bool is_add); // 修改道具
    void Change_Blood(int num); // 更改血量
    void Change_Starveness(int num); // 更改饥饿值
    bool read_attr();
    bool write_attr();
};

#endif