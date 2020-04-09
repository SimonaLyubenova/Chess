#pragma once
#include "Piece.h"

class Knight:public Piece
{
public:
    Knight();
    virtual bool moveMe(int, int, int, int, Color, Color);
};
