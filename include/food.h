#ifndef _FOOD_H
#define _FOOD_H

#include<string>
class food
{
    protected:
        int satiety;
        int treatment;
        int san;

    public:
        food(int _satiety, int _treatment, int _san) : satiety(_satiety), treatment(_treatment), san(_san){};
        virtual void show(){};
        virtual ~food(){};
        // void use_food();
};

class apple : private food
{
    protected:
        static const std::string name;
        static const std::string description;
    public:
        apple(int _satiety = 5, int _treatment = 5, int _san = 2) : food(_satiety, _treatment, _san){};
        void show();
        ~apple() = default;
        // void use_apple();
};


#endif