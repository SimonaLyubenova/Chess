#include <iostream>
#include "Pawn.h"

Pawn::Pawn()
{
    setName('P');
}

bool Pawn::moveMe(int sourceX, int sourceY, int destinationX, int destinationY, Color source_color, Color destination_color)
{
    bool invalid = false;

    if (source_color == WHITE)
    {
        if (sourceX == destinationX && destinationY == sourceY + 1 && destination_color == NONE)
        {
            return true;
        }
        else
        {
            if ((sourceX + 1 == destinationX || sourceX - 1 == destinationX) && sourceY + 1 == destinationY  && destination_color == BLACK)
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
                if ((sourceX + 1 == destinationX || sourceX - 1 == destinationX) && sourceY - 1 == destinationY  && source_color == WHITE)
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
}
