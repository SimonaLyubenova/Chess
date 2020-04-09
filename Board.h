#pragma once
#include "Square.h"
#include "Enums.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Empty.h"

static Square board[8][8];

class Board
{
	Color turn=WHITE;
	bool makeMove(int x1, int y1, int x2, int y2);
	void printBoard();
public:
	Square* getSquare(int x, int y);
	void setSquare(Square* newSquare, int x, int y);
	bool doMove();

	void setBoard();
	bool playGame();
};
