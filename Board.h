#pragma once
#include "Enums.h"
#include "Square.h"

#include <iostream>
#include <cmath>
#include <string>

class Board
{
	Square square[8][8];
	Color turn=WHITE;
	bool moveKing(Square* thisKing, Square* thatSpace);
	bool moveQueen(Square* thisQueen, Square* thatSpace);
	bool moveBishop(Square* thisBishop, Square* thatSpace);
	bool moveKnight(Square* thisKnight, Square* thatSpace);
	bool moveRook(Square* thisRook, Square* thatSpace);
	bool movePawn(Square* thisPawn, Square* thatSpace);
	bool makeMove(int x1, int y1, int x2, int y2);
	void printBoard();
public:
	Square* getSquare(int x, int y);
	void setSquare(Square* newSquare, int x, int y);
	bool doMove();

	void setBoard();
	bool playGame();
};
