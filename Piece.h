#pragma once
#include "Enums.h"

class Piece
{
    char name;

public:
    void setName(char);
    char getName();

    virtual bool moveMe(int, int, int, int, Color, Color) {}
};
