#ifndef _IO_H
#define _IO_H

#include<vector>
#include<string>

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

class IO
{
    private:
        std::string get_file_name(int floor);

    public:
        IO() = default;
        bool read_map(map_data &data);
        bool write_map(map_data &data);
        // bool read_attributes();
        // bool write_attributes();
};

#endif