#ifndef START_GAME_H
#define START_GAME_H

#include<string>
#include<stdbool.h>

#define Max_Weapon 10
#define Max_Props 10


class Attributes {
private:
    unsigned long Weapons_Num;
    unsigned long Props_Num;
    std::string Weapons[Max_Weapon]; // 武器
    std::string Props[Max_Props];// 道具
    unsigned long Blood; // 血量
    unsigned long Starveness; // 饥饿值
    unsigned long floor;
public:
    Attributes ();
    void Show_Floor();
    void Show_Blood();
    void Show_Starveness();
    void Show_Weapons();
    void Show_Props();
    void Add_Weapons(std::string w, bool is_add);
    void Add_Props(std::string w, bool is_add);
    void Change_Blood(int num);
    void Change_Starveness(int num);
};

#endif