#include <iostream>
#include "Bishop.h"
#include "Board.h"

Bishop::Bishop()
{
    setName('B');
}

bool Bishop::moveMe(std::pair<int,int> sourceCoordinates, std::pair<int,int> destinationCoordinates, Color source_color, Color destination_color)
{
    int sourceX = sourceCoordinates.first;
    int sourceY = sourceCoordinates.second;
    int destinationX = destinationCoordinates.first;
    int destinationY = destinationCoordinates.second;

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

    return true;
}
