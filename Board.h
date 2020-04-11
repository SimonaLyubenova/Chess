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

extern Square board[8][8];

class Board
{
    Color turn=WHITE;

    void setTurnColor(Color newTurn);
    Color getTurnColor() const;

    bool checkOutOfBounds(int x1, int y1, int x2, int y2);
    bool checkForDifferentColorPieces(Square* source, Square* destination);
    bool checkIfSourcePieceIsNoEmpty(Square* source);
    bool makeMoveIfValid(int x1, int y1, int x2, int y2);

    bool checkIfDestinationIsKing(Square* destination);
    bool checkIfSourceIsWhite(Square* source);

    void setPiecesWithoutPawnsAndEmpty();
    void setPawns();
    void setEmptyPieces();
    void setPiecesOnTheDesk();
    void printBoard();

    Square* getSquare(int x, int y);
    void setSquare(Square* newSquare, int x, int y);
    bool doMove();

public:
    void setBoard();
    bool playGame();
};
