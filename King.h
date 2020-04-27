#pragma once
#include "Piece.h"

class King:public Piece
{
public:
    King();
    virtual bool moveMe(std::pair<int,int>, std::pair<int,int>, Color, Color);
};
