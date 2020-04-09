#include <iostream>
#include "Square.h"

Square::Square()
{
	this->piece = EMPTY;
	this->color = NONE;
}

void Square::setSpace(Square* space)
{
	this->color = space->getColor();
	this->piece = space->getPiece();
}

void Square::setEmpty()
{
	this->color = NONE;
	this->piece = EMPTY;
}

const Piece Square::getPiece()
{
	return this->piece;
}

const Color Square::getColor()
{
	return this->color;
}

void Square::setPieceAndColor(Piece newPiece, Color newColor)
{
	this->piece = newPiece;
	this->color = newColor;
}

void Square::setX(int newX)
{
    this->x = newX;
}

const int Square::getX()
{
    return this->x;
}

void Square::setY(int newY)
{
    this->y = newY;
}

const int Square::getY()
{
    return this->y;
}
