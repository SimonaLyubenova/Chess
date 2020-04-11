#pragma once
#include "Piece.h"

class King:public Piece
{
public:
    King();

    virtual bool moveMe(int, int, int, int, Color, Color);
};
