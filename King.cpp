#include <iostream>
#include "King.h"

King::King()
{
    setName('K');
}

bool King::moveMe(std::pair<int,int> sourceCoordinates, std::pair<int,int> destinationCoordinates, Color source_color, Color destination_color)
{
    int sourceX = sourceCoordinates.first;
    int sourceY = sourceCoordinates.second;
    int destinationX = destinationCoordinates.first;
    int destinationY = destinationCoordinates.second;

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

    return true;
}
