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
        attr.Show_Floor();
        Map m;
        m.Draw_Map();
        while(1);
    }    
    while (1) {};
    return 0;
}