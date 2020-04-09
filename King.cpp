#include <iostream>
#include "King.h"

King::King()
{
    setName('K');
}

bool King::moveMe(int src_x, int src_y, int dest_x, int dest_y, Color src_color, Color dest_color)
{
    if (abs(dest_x - src_x) == 1)
    {
		if (abs(dest_y - src_y) == 1)
		{
			return true;
		}
		else
        {
            return false;
        }
    }
	else
    {
        return false;
    }
}
