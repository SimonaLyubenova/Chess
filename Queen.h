#pragma once
#include "Piece.h"

class Queen:public Piece
{
public:
    Queen();
    virtual bool moveMe(std::pair<int,int>, std::pair<int,int>, Color, Color);
};
