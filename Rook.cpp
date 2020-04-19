#include <iostream>
#include "Board.h"
#include "Rook.h"

Rook::Rook()
{
    setName('R');
}

bool Rook::moveMe(int sourceX, int sourceY, int destinationX, int destinationY, Color source_color, Color destination_color)
{
    bool invalid = false;

    if (sourceX != destinationX || sourceY != destinationY)
    {
        if (sourceX == destinationX)
        {
            int yIncrement = (destinationY - sourceY) / (abs(destinationY - sourceY));
            for (int i = sourceY + yIncrement; i != destinationY; i += yIncrement)
            {
                Square* pieceIncrement = &board[destinationX][i];
                if (pieceIncrement->getColor() != NONE)
                {
                    return false;
                }
            }
        }
        else
        {
            if (sourceY == destinationY)
            {
                int xIncrement = (destinationX - sourceX) / (abs(destinationX - sourceX));
                for (int i = sourceX + xIncrement; i != destinationX; i += xIncrement)
                {
                    Square* pieceIncrement = &board[i][destinationY];
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
        }
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
