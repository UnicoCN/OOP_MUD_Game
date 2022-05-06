#include<iostream>
#include<windows.h>
#include<string>

#include "../include/map.h"

void Map::Draw_Map() {
    SetConsoleOutputCP(65001);
    for (int i = 0;  i < width; ++i)
        std::cout << "-";
    std::cout << std::endl;
    int del_block[5];
    memset(del_block,0,sizeof(del_block));
    for (int i = height-1; i >= 0; --i) {
        for (int j = 0; j < width; ++j) {
            if (j == human_x && i == human_y) {
                del_block[i] ++;
                std::cout << "人";
                continue;
            } 
            if (j == light_x && i ==  light_y) {
                del_block[i] ++;
                std::cout << "灯";
                continue;
            }
            if (j == monster_x && i == monster_y) {
                del_block[i] ++;
                std::cout << "怪";
                continue;
            }
            if (j == door_x && i == door_y) {
                del_block[i] ++;
                std::cout << "门";
                continue;
            }
            if (j == stairs_x && i == stairs_y) {
                del_block[i] ++;
                std::cout << "梯";
                continue;
            }
            if (j == width -1 - del_block[i]) std::cout << "|" << std::endl;
            std::cout << " ";
        }
    }
    for (int i = 0;  i < width; ++i)
        std::cout << "-";
    std::cout << std::endl;
}