#include "include/start_menu.h"
#include "include/attributes.h"
#include "include/map.h"
#include "include/IO.h"
#include "include/play_music.h"
#include "include/environment_setting.h"
#include "include/food.h"

int main() {
    start_menu Menu;
    environment_setting();
    
    play_music test;
    test.start_play();

    int choice = Menu.dead_lock();
    if (choice == 0) {
        system("cls");
        Attributes attr;
        attr.Show_Blood();
        attr.Show_Starveness();
        attr.Show_Weapons();
        attr.Show_Props();
        Map m;
        IO io_ini;
        io_ini.read_map(m);
        m.Show_Floor();
        m.Draw_Map();
        m.Listen_Keyboard();
    }
    else if(choice == 1)
    {
        /*IO read;
        Map test;
        test.floor = 7;
        read.read_map(test);
        system("cls");
        auto it = test.light.begin();
        for(; it != test.light.end(); it++)
            printf("%d %d\n", (*it).first, (*it).second);
        while(1);*/

        apple test;
        test.show();
        while(1);
    }
    return 0;
}