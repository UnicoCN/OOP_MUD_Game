#include "include/start_menu.h"
#include "include/attributes.h"
#include "include/map.h"

int main() {
    start_menu Menu;
    int choice = Menu.dead_lock();
    if (choice == 0) {
        system("cls");
        Attributes attr;
        attr.Show_Blood();
        attr.Show_Starveness();
        attr.Show_Weapons();
        attr.Show_Props();
        Map m;
        m.Show_Floor();
        m.Draw_Map();
        m.Listen_Keyboard();
    }    
    return 0;
}