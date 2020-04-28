#pragma once
#include "Piece.h"

class Rook:public Piece
{
public:
    Rook();
    virtual bool moveMe(std::pair<int,int>, std::pair<int,int>, Color, Color);
};
