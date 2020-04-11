#include <iostream>
#include "Bishop.h"
#include "Board.h"

Bishop::Bishop()
{
    setName('B');
}

bool Bishop::moveMe(int src_x, int src_y, int dest_x, int dest_y, Color src_color, Color dest_color)
{
    int bishopX = src_x;
    int bishopY = src_y;
    int thatX = dest_x;
    int thatY = dest_y;
    bool invalid = false;
    if (abs(bishopX - thatX) == abs(bishopY - thatY))
    {
        int xIncrement = (thatX - bishopX) / (abs(thatX - bishopX));
        int yIncrement = (thatY - bishopY) / (abs(thatY - bishopY));

        for (int i = 1; i < abs(bishopX - thatX); i++)
        {
            if (board[bishopX + xIncrement*i][bishopY + yIncrement*i].getColor() != NONE)
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }

    if (invalid == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}
