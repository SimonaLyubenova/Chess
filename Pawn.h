#pragma once
#include "Piece.h"

class Pawn:public Piece
{
public:
    Pawn();
    virtual bool moveMe(int, int, int, int, Color, Color);
};
