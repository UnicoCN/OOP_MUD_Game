#ifndef _MAP_H
#define _MAP_H

#include <vector>

class map_data
{
    public:
        int floor;
        std::pair<int, int> people;
        std::vector<std::pair<int, int>> light;
        std::vector<std::pair<int, int>> monster;
        std::vector<std::pair<int, int>> door;
        std::vector<std::pair<int, int>> stair;
        std::vector<std::pair<int, int>> object;

        map_data() = default;
};


class Map : public map_data {
private:
    const int height = 5;
    const int width = 160;
public:
    Map () {
        floor = 7;
    }
    void Show_Floor();
    void Draw_Map();
    void Update_Map();
    void Change_Human_Position(int dis);
    void Listen_Keyboard();
    /* 判断当前坐标是否有物品 */
    int Check_Object(int x, int y);
    void Draw_Menu();
};

#endif