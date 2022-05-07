#ifndef MAP_H
#define MAP_H

class Map {
private:
    unsigned long width = 160;
    unsigned long height = 5;
    unsigned long human_x = 80;
    unsigned long human_y = 0;
    unsigned long stairs_x = 5;
    unsigned long stairs_y = 0;
    unsigned long door_x = 15;
    unsigned long door_y = 0;
    unsigned long light_x = 80;
    unsigned long light_y = 4;
    unsigned long monster_x = 100;
    unsigned long monster_y = 0;
    unsigned long floor;
public:
    Map () {
        floor = 10;
    }
    void Show_Floor();
    void Draw_Map();
    void Change_Human_Position(int dis);
    void Listen_Keyboard();
};

#endif