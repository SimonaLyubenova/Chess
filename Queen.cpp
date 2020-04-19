#include <iostream>
#include "Board.h"
#include "Queen.h"

Queen::Queen()
{
    setName('Q');
}

bool Queen::moveMe(int sourceX, int sourceY, int destinationX, int destinationY, Color source_color, Color destination_color)
{
    int xIncrement;
    int yIncrement;

    bool invalid = false;
    if (sourceX != destinationX || sourceY != destinationY)
    {
        if (sourceX == destinationX)
        {
            yIncrement = (destinationY - sourceY) / (abs(destinationY - sourceY));
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
                xIncrement = (destinationX - sourceX) / (abs(destinationX - sourceX));
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
                if (abs(sourceX - destinationX) == abs(sourceY - destinationY))
                {
                    xIncrement = (destinationX - sourceX) / (abs(destinationX - sourceX));
                    yIncrement = (destinationY - sourceY) / (abs(destinationY - sourceY));

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
