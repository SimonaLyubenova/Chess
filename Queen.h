#pragma once
#include "Piece.h"

class Queen:public Piece
{
public:
    Queen();

    virtual bool moveMe(int, int, int, int, Color, Color);
};
