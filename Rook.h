#pragma once
#include "Piece.h"

class Rook:public Piece
{
public:
    Rook();

    virtual bool moveMe(int, int, int, int, Color, Color);
};
