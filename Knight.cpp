#include <iostream>
#include "Knight.h"

Knight::Knight()
{
    setName('H');
}

bool Knight::moveMe(int sourceX, int sourceY, int destinationX, int destinationY, Color source_color, Color destination_color)
{
    if ((abs(sourceX - destinationX) == 2 && abs(sourceY - destinationY) == 1) ||
            (abs(sourceX - destinationX) == 1 && abs(sourceY - destinationY) == 2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
