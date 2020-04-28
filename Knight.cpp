#include <iostream>
#include "Knight.h"

Knight::Knight()
{
    setName('H');
}

bool Knight::moveMe(std::pair<int,int> sourceCoordinates, std::pair<int,int> destinationCoordinates, Color source_color, Color destination_color)
{
    int sourceX = sourceCoordinates.first;
    int sourceY = sourceCoordinates.second;
    int destinationX = destinationCoordinates.first;
    int destinationY = destinationCoordinates.second;

    if ((abs(sourceX - destinationX) == 2 && abs(sourceY - destinationY) == 1) ||
            (abs(sourceX - destinationX) == 1 && abs(sourceY - destinationY) == 2))
    {
        return true;
    }
    else
    {
        return false;
    }

    return true;
}
