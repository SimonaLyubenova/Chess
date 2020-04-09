#include <iostream>
#include "Board.h"
#include "Queen.h"

Queen::Queen()
{
    setName('Q');
}

bool Queen::moveMe(int src_x, int src_y, int dest_x, int dest_y, Color src_color, Color dest_color)
{
    int queenX = src_x;
	int queenY = src_y;
	int thatX = dest_x;
	int thatY = dest_y;
	std::cout << "this";

	int xIncrement;
	int yIncrement;

	bool invalid = false;
	if (queenX != thatX || queenY != thatY)
	{
		if (queenX == thatX)
		{
            yIncrement = (thatY - queenY) / (abs(thatY - queenY));
            for (int i = queenY + yIncrement; i != thatY; i += yIncrement)
            {
                if (board[thatX][i].getColor() != NONE)
                {
                    return false;
                }
            }
		}
		else
        {
            if (queenY == thatY)
			{
                xIncrement = (thatX - queenX) / (abs(thatX - queenX));
                for (int i = queenX + xIncrement; i != thatX; i += xIncrement)
                {
                    if (board[i][thatY].getColor() != NONE)
                    {
                        return false;
                    }
                }
			}
			else
            {
                if (abs(queenX - thatX) == abs(queenY - thatY))
				{
                    xIncrement = (thatX - queenX) / (abs(thatX - queenX));
                    yIncrement = (thatY - queenY) / (abs(thatY - queenY));

                    for (int i = 1; i < abs(queenX - thatX); i++)
                    {
                        std::cout << "It got here somehow";
                        if (board[queenX + xIncrement*i][queenY + yIncrement*i].getColor() != NONE)
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
