#include <iostream>
#include "Bishop.h"
#include "Board.h"

Bishop::Bishop()
{
    setName('B');
}

bool Bishop::moveMe(int sourceX, int sourceY, int destinationX, int destinationY, Color source_color, Color destination_color)
{
    bool invalid = false;

    if (abs(sourceX - destinationX) == abs(sourceY - destinationY))
    {
        int xIncrement = (destinationX - sourceX) / (abs(destinationX - sourceX));
        int yIncrement = (destinationY - sourceY) / (abs(destinationY - sourceY));

        for (int i = 1; i < abs(sourceX - destinationX); i++)
        {
            Square* pieceIncrement = &board[sourceX + xIncrement*i][sourceY + yIncrement*i];
            if (pieceIncrement->getColor() != NONE)
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
