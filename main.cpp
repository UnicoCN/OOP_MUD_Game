#include "include/start_menu.h"
#include "include/attributes.h"
#include "include/map.h"
#include "include/IO.h"
#include "include/play_music.h"
#include "include/environment_setting.h"
#include "include/about_us.h"
#include "include/food.h"
#include "include/interact.h"
#include <ctime>

start_menu Menu;
Map m;
About_US as;
Attributes attr;
interact inter;

int main() {
    srand((unsigned)time(NULL));
    environment_setting();    
    play_music test;
    test.start_play();
    Menu.Choose();
    return 0;
}