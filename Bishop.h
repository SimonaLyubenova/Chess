#pragma once
#include "Piece.h"

class Bishop:public Piece
{
public:
    Bishop();
    virtual bool moveMe(std::pair<int,int>, std::pair<int,int>, Color, Color);
};
