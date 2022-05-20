#ifndef _IO_H
#define _IO_H

#include<vector>
#include<string>
#include "./map.h"

class IO
{
    private:
        std::string get_file_name(int floor);

    public:
        IO() = default;
        bool read_map(Map &data);
        bool write_map(Map &data);
};

#endif