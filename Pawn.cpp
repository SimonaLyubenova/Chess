#include <iostream>
#include "Pawn.h"

Pawn::Pawn()
{
    setName('P');
}

bool Pawn::moveMe(int src_x, int src_y, int dest_x, int dest_y, Color src_color, Color dest_color)
{
    bool invalid = false;
    int pawnX = src_x;
    int pawnY = src_y;
    int thatX = dest_x;
    int thatY = dest_y;

    if (src_color == WHITE)
    {
        if (pawnX == thatX && thatY == pawnY + 1 && dest_color == NONE)
        {
            return true;
        }
        else
        {
            if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY + 1 == thatY  && dest_color == BLACK)
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
        if (src_color == BLACK)
        {
            if (pawnX == thatX && thatY == pawnY - 1 && dest_color == NONE)
            {
                return true;
            }
            else
            {
                if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY - 1 == thatY  && src_color == WHITE)
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
