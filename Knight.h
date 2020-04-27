#pragma once
#include "Piece.h"

class Knight:public Piece
{
public:
    Knight();
    virtual bool moveMe(std::pair<int,int>, std::pair<int,int>, Color, Color);
};
