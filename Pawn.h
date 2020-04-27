#pragma once
#include "Piece.h"

class Pawn:public Piece
{
public:
    Pawn();
    virtual bool moveMe(std::pair<int,int>, std::pair<int,int>, Color, Color);
};
