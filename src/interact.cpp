#include "../include/interact.h"
#include "../include/attributes.h"
#include "../include/map.h"
#include "../include/IO.h"

#include<conio.h>
#include<iostream>

extern Attributes attr;
extern Map m;

void interact::start_interact(int choice, int up_or_down)
{
    switch (choice)
    {
        case 2:
            interact_with_monster();
            break;
        case 3:
            interact_with_door();
            break;
        case 4:
            interact_with_stairs(up_or_down);
            break;
        default:
            break;
    }
}

void interact::interact_with_door()
{
    int add_number;
    int door_number = rand() % 10;
    switch (door_number)
    {
        case 0:
        case 1:
            attr.Change_Starveness(-10);
            attr.Change_Blood(-10);
            attr.Add_Props("怪物肉", true);
            add_number = rand() % 10;
            switch (add_number)
            {
                case 0:
                case 1:
                    attr.Add_Weapons("消防斧", true); 
                    break;
                case 2:
                case 3:
                case 4:
                    attr.Add_Weapons("水果刀", true);
                    break;
                default:
                    attr.Add_Weapons("普通的木棍", true);
                    break;
            }
            break;
        case 2:
        case 3:
            attr.Change_Starveness(-10);
            add_number = rand() % 10;
            switch(add_number)
            {
                case 0:
                case 1:
                case 2:
                    attr.Add_Props("急救包", true);
                    attr.Add_Props("苹果", true);
                    break;
                case 3:
                case 4:
                case 5:
                case 6:
                    attr.Add_Props("止痛药", true);
                    attr.Add_Props("罐头", true);
                    break;
                default:
                    attr.Add_Props("纱布", true);
                    attr.Add_Props("军用干粮", true);
                    break;
            }
            break;
        case 4:
        case 5:
            attr.Change_Starveness(-10);
            attr.Change_Blood(-10);
            add_number = rand() % 10;
            switch(add_number)
            {
                case 0:
                case 1:
                case 2:
                    attr.Add_Props("苹果", true);
                    attr.Add_Weapons("水果刀", true);
                    break;
                case 3:
                case 4:
                case 5:
                case 6:
                    attr.Add_Props("急救包", true);
                    break;
                default:
                    attr.Add_Weapons("消防斧", true);
                    break;
            }
            break;
        default:
            attr.Change_Starveness(-10);
            attr.Change_Blood(10);
            break;
    }
    attr.Re_Show_All();
}

void interact::interact_with_monster()
{
    int monster_life = rand() % 20 + 20;
    int monster_attack = rand() % 10 + 10;
    int human_attack = attr.Get_Attack();
    while(monster_life >= 0)
    {
        int p = rand() % 10;
        if(p >= 8)
            monster_life -= 2 * human_attack;
        else
            monster_life -= human_attack;
        attr.Change_Blood(-monster_attack);
    }
    attr.Re_Show_All();
    return;
}

void interact::interact_with_stairs(int up_or_down)
{
    if (up_or_down == 1) {
        system("cls");
        if (m.floor > 1) {
            attr.write_attr(1);
            attr.Show_All();
            IO io_ini;
            io_ini.write_map(m,1);
            m.floor --;
            io_ini.read_map(m,0);
            m.Show_Floor();
            m.Draw_Map();
            m.Listen_Keyboard();
        } else {
            attr.write_attr(1);
            attr.Show_All();
            IO io_ini;
            io_ini.write_map(m,1);
            io_ini.read_map(m,1);
            m.Show_Floor();
            m.Draw_Map();
            m.Listen_Keyboard();
        }
    } else {
        system("cls");
        if (m.floor < 7) { 
            attr.write_attr(1);
            attr.Show_All();
            IO io_ini;
            io_ini.write_map(m,1);
            m.floor ++;
            io_ini.read_map(m,0);
            m.Show_Floor();
            m.Draw_Map();
            m.Listen_Keyboard();
        } else {
            attr.write_attr(1);
            attr.Show_All();
            IO io_ini;
            io_ini.write_map(m,1);
            io_ini.read_map(m,1);
            m.Show_Floor();
            m.Draw_Map();
            m.Listen_Keyboard();
        }
    }
    return;
}