#ifndef _INTERACT_H
#define _INTERACT_H

class interact
{
    private:
        void interact_with_door();
        void interact_with_monster();
        void interact_with_stairs();
    public:
        void start_interact(int choice = 0);
};

#endif