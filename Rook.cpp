#include <iostream>
#include "Board.h"
#include "Rook.h"

Rook::Rook()
{
    setName('R');
}

bool Rook::moveMe(int src_x, int src_y, int dest_x, int dest_y, Color src_color, Color dest_color)
{
    int rookX = src_x;
	int rookY = src_y;
	int thatX = dest_x;
	int thatY = dest_y;
	bool invalid = false;
	if (rookX != thatX || rookY != thatY)
	{
		if (rookX == thatX)
		{
			int yIncrement = (thatY - rookY) / (abs(thatY - rookY));
			for (int i = rookY + yIncrement; i != thatY; i += yIncrement)
			{
				if (board[thatX][i].getColor() != NONE)
				{
				    return false;
				}
			}
		}
		else
        {
            if (rookY == thatY)
			{
				int xIncrement = (thatX - rookX) / (abs(thatX - rookX));
				for (int i = rookX + xIncrement; i != thatX; i += xIncrement)
				{
					if (board[i][thatY].getColor() != NONE)
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
		std::cout << "That is an invalid move for rook";
		return false;
	}
}
