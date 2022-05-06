#ifndef START_MENU_H
#define START_MENU_H

#include<string>

class start_menu  
{
    private:
        int choice;
        std::string menu[4];
        std::string lots_of_tab;
    public:
        start_menu(int _choice = 0) : choice(_choice)
        {
            menu[0] = "开始游戏";
            menu[1] = "继续游戏";
            menu[2] = "游戏设置";
            menu[3] = "退出游戏";
            lots_of_tab = ";                                                                                             ";
        }
        int dead_lock();
        void print_menu();
        void print_pic();
        void reprint_menu();
        int input_check();
};



#endif