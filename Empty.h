#pragma once
#include "Piece.h"

class Empty:public Piece
{
public:
    Empty();
    virtual bool moveMe(std::pair<int,int>, std::pair<int,int>, Color, Color) {}
};
