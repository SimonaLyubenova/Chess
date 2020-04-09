#pragma once
#include "Enums.h"

#include <iostream>
#include <cmath>
#include <string>

class Square
{
	Piece piece;
	Color color;
	int x, y;

public:
    Square();
	void setSpace(Square*);
	void setEmpty();
	void setPieceAndColor(Piece, Color);
	const Piece getPiece();
	const Color getColor();
	void setX(int);
	void setY(int);
	const int getX();
	const int getY();
};
