#include <iostream>
#include <cmath>
#include "Square.h"

Square::Square()
{
    setEmpty();
}

void Square::setSpace(Square* space)
{
    this->color = space->getColor();
    this->piece = space->getPiece();
}

void Square::setEmpty()
{
    Empty* empty_piece = new Empty();
    this->piece = empty_piece;
    this->color = NONE;
}

Piece* Square::getPiece()
{
    return this->piece;
}

Color Square::getColor()
{
    return this->color;
}

void Square::setPieceAndColor(Piece* newPiece, Color newColor)
{
    this->piece = newPiece;
    this->color = newColor;
}

void Square::setX(int newX)
{
    this->x = newX;
}

int Square::getX() const
{
    return this->x;
}

void Square::setY(int newY)
{
    this->y = newY;
}

int Square::getY() const
{
    return this->y;
}

Square::~Square()
{
    delete this->piece;
}
