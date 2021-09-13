#ifndef FOOD_H
#define FOOD_H

#include <windows.h> //for position
#include <cstdlib> //for random position of food

#define WIDTH 50
#define HEIGHT 25
class Food
{
private:
    COORD pos;

public:
    Food();
    void gen_food(); //generate food
    COORD get_pos();

};

#endif // FOOD_H
