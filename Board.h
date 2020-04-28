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

    bool checkOutOfBounds(Square*, Square*);
    bool checkForSameColorPieces(Square*, Square*);
    bool checkIfSourcePieceIsEmpty(Square*);
    bool makeMoveIfValid(Square*, Square*);

    bool checkIfDestinationIsKing(Square*);

    void setPiecesWithoutPawnsAndEmpty();
    void setPawns();
    void setEmptyPieces();
    void setAllPiecesOnTheDesk();
    void printBoard();

    Square* getSquare(int, int);
    void setSquare(Square*, int, int);
    bool doMove();

public:
    void setBoard();
    bool playGame();
};
