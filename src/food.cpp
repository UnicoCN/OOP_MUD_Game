#include<iostream>

#include "../include/food.h"

void apple::show()
{
    std::cout << name << std::endl;
    std::cout << description << std::endl;
    std::cout << satiety << std::endl;
    std::cout << treatment << std::endl;
    std::cout << san << std::endl;
    return;
}

const std::string apple::name = "苹果";
const std::string apple::description = "平日里很常见的一种水果，可惜今时不同往日，对吧？";