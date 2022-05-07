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
        /* 初始化菜单 */
        start_menu(int _choice = 0) : choice(_choice)
        {
            menu[0] = "开始游戏";
            menu[1] = "继续游戏";
            menu[2] = "游戏设置";
            menu[3] = "退出游戏";
            lots_of_tab = "                                                                                             ";
        }
        int dead_lock(); // 初始化菜单界面
        void print_menu(); // 输出菜单
        void print_pic(); // 输出字符画
        void reprint_menu(); // 菜单刷新
        int input_check(); // 键盘监听
};



#endif