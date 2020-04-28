#pragma once
#include "Enums.h"

class Piece
{
    char name;

public:
    void setName(char);
    char getName() const;
    virtual bool moveMe(std::pair<int,int>, std::pair<int,int>, Color, Color) {}
};
