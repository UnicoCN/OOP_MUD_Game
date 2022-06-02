#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "../include/IO.h"
#include "../include/map.h"

std::string IO::get_file_name(int floor, int option)
{
    char *temp = new char[5];
    ltoa(floor, temp, 10);
    std::string test = temp;
    delete[] temp;
    std::string result;
    if (option == 1) result = ".\\save\\save" + test + ".txt";
        else if (option == 0) result = ".\\new\\new_map.txt";
    return result;
}

bool IO::write_map(Map &data, int option)
{
    std::ofstream out_stream;
    std::string file_name = get_file_name(data.floor, option);
    out_stream.open(file_name);
    if (!out_stream)
        return false;
    else
    {
        out_stream << "People:" << std::endl;
        out_stream << (data.people).first << ' ' << (data.people).second << std::endl;
        out_stream << -1 << ' ' << -1 << std::endl;
        auto it = data.light.begin();

        out_stream << "Light:" << std::endl;
        for (; it != data.light.end(); ++it)
            out_stream << (*it).first << ' ' << (*it).second << std::endl;
        out_stream << -1 << ' ' << -1 << std::endl;

        out_stream << "Monster:" << std::endl;
        for (it = data.monster.begin(); it != data.monster.end(); ++it)
            out_stream << (*it).first << ' ' << (*it).second << std::endl;
        out_stream << -1 << ' ' << -1 << std::endl;

        out_stream << "Door:" << std::endl;
        for (it = data.door.begin(); it != data.door.end(); ++it)
            out_stream << (*it).first << ' ' << (*it).second << std::endl;
        out_stream << -1 << ' ' << -1 << std::endl;

        out_stream << "Stair:" << std::endl;
        for (it = data.stair.begin(); it != data.stair.end(); ++it)
            out_stream << (*it).first << ' ' << (*it).second << std::endl;
        out_stream << -1 << ' ' << -1 << std::endl;

        out_stream.close();
        return true;
    }
}

bool IO::read_map(Map &data, int option)
{
    data.light.clear();
    data.door.clear();
    data.monster.clear();
    data.stair.clear();
    std::ifstream in_stream;
    std::string file_name = get_file_name(data.floor, option);
    in_stream.open(file_name);
    if (!in_stream)
        return false;
    else
    {
        std::string type;
        int x, y;
        while (in_stream >> type)
        {
            if (type == "People:")
            {
                while (1)
                {
                    in_stream >> x >> y;
                    if (x == -1 && y == -1)
                        break;
                    data.people = std::make_pair(x, y);
                }
                continue;
            }

            if (type == "Light:")
            {
                while (1)
                {
                    in_stream >> x >> y;
                    if (x == -1 && y == -1)
                        break;
                    data.light.push_back(std::make_pair(x, y));
                }
                continue;
            }

            if (type == "Monster:")
            {
                while (1)
                {
                    in_stream >> x >> y;
                    if (x == -1 && y == -1)
                        break;
                    data.monster.push_back(std::make_pair(x, y));
                }
                continue;
            }

            if (type == "Door:")
            {
                while (1)
                {
                    in_stream >> x >> y;
                    if (x == -1 && y == -1)
                        break;
                    data.door.push_back(std::make_pair(x, y));
                }
                continue;
            }

            if (type == "Stair:")
            {
                while (1)
                {
                    in_stream >> x >> y;
                    // std::cout << x << "," << y << std::endl;
                    if (x == -1 && y == -1)
                        break;
                    data.stair.push_back(std::make_pair(x, y));
                }
                continue;
            }
        }
        return true;
    }
}