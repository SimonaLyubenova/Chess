#include <iostream>
#include "Pawn.h"

Pawn::Pawn()
{
    setName('P');
}

bool Pawn::moveMe(std::pair<int,int> sourceCoordinates, std::pair<int,int> destinationCoordinates, Color source_color, Color destination_color)
{
    int sourceX = sourceCoordinates.first;
    int sourceY = sourceCoordinates.second;
    int destinationX = destinationCoordinates.first;
    int destinationY = destinationCoordinates.second;

    if (source_color == WHITE)
    {
        if (sourceX == destinationX && destinationY == sourceY + 1 && destination_color == NONE)
        {
            return true;
        }
        else
        {
            if ((sourceX + 1 == destinationX || sourceX - 1 == destinationX) && sourceY + 1 == destinationY && destination_color == BLACK)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        if (source_color == BLACK)
        {
            if (sourceX == destinationX && destinationY == sourceY - 1 && destination_color == NONE)
            {
                return true;
            }
            else
            {
                if ((sourceX + 1 == destinationX || sourceX - 1 == destinationX) && sourceY - 1 == destinationY && destination_color == WHITE)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}
