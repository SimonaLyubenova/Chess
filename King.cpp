#include <iostream>
#include "King.h"

King::King()
{
    setName('K');
}

bool King::moveMe(int sourceX, int sourceY, int destinationX, int destinationY, Color source_color, Color destination_color)
{
    if (abs(destinationX - sourceX) == 1)
    {
        if (abs(destinationY - sourceY) == 0 || abs(destinationY - sourceY) == 1)
        {
            return true;
        }
    }
    else
    {
        if (abs(destinationX - sourceX) == 0)
        {
            if (abs(destinationY - sourceY) == 1)
            {
                return true;
            }
        }
        return false;
    }
}
