#ifndef _IO_H
#define _IO_H

#include<vector>
#include<string>
#include "./map.h"

class IO
{
    private:
        std::string get_file_name(int floor, int option);

    public:
        IO() = default;
        bool read_map(Map &data, int option);
        bool write_map(Map &data, int option);
};

#endif