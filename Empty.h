#pragma once
#include "Piece.h"

class Empty:public Piece
{
public:
    Empty();

    virtual bool moveMe(int, int, int, int, Color, Color) {}
};
