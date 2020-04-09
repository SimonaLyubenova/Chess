#pragma once
#include "Piece.h"

class Bishop:public Piece
{
public:
    Bishop();
    virtual bool moveMe(int, int, int, int, Color, Color);
};
