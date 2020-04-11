#include <iostream>
#include "Knight.h"

Knight::Knight()
{
    setName('H');
}

bool Knight::moveMe(int src_x, int src_y, int dest_x, int dest_y, Color src_color, Color dest_color)
{
    int knightX = src_x;
    int knightY = src_y;
    int thatX = dest_x;
    int thatY = dest_y;

    if ((abs(knightX - thatX) == 2 && abs(knightY - thatY) == 1) || (abs(knightX - thatX) == 1 && abs(knightY - thatY) == 2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
