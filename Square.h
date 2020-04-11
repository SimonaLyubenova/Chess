#pragma once
#include "Enums.h"
#include "Empty.h"

class Square
{
    Piece* piece=nullptr;
    Color color;
    int x, y;

public:
    Square();
    void setSpace(Square*);
    void setEmpty();
    void setPieceAndColor(Piece*, Color);
    Piece* getPiece();
    Color getColor();
    void setX(int);
    void setY(int);
    int getX() const;
    int getY() const;
    ~Square();
};
