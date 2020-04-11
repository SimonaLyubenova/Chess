#include <iostream>
#include <cmath>
#include <string>
#include "Board.h"

using namespace std;

Square* Board::getSquare(int x, int y)
{
    return &board[x][y];
}

void Board::setSquare(Square* newSquare, int x, int y)
{
    board[x][y] = *newSquare;
}

void Board::setTurnColor(Color newTurn)
{
    this->turn = newTurn;
}

Color Board::getTurnColor() const
{
    return this->turn;
}

void Board::printBoard()
{
    cout << "   y: 0  1  2  3  4  5  6  7 " << endl << "x:" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << " " << i << "   ";
        for (int j = 0; j < 8; j++)
        {
            Piece* thisPiece = new Piece();
            thisPiece = board[i][j].getPiece();
            Color thisColor = board[i][j].getColor();

            switch (thisPiece->getName())
            {
            case 'K':
                (thisColor == WHITE) ? cout << " K " : cout << " k ";
                break;
            case 'Q':
                (thisColor == WHITE) ? cout << " Q " : cout << " q ";
                break;
            case 'B':
                (thisColor == WHITE) ? cout << " B " : cout << " b ";
                break;
            case 'H':
                (thisColor == WHITE) ? cout << " H " : cout << " h ";
                break;
            case 'R':
                (thisColor == WHITE) ? cout << " R " : cout << " r ";
                break;
            case 'P':
                (thisColor == WHITE) ? cout << " P " : cout << " p ";
                break;
            case 'E':
                cout << " " << "\21" << " ";
                break;
            default:
                cout << "XXX";
                break;
            }
        }
        cout << endl;
    }
}

bool Board::checkIfDestinationIsKing(Square* destination)
{
    if (destination->getPiece()->getName() == 'K' || destination->getPiece()->getName() == 'k')
    {
        return true;
    }
    return false;
}

bool Board::checkIfSourceIsWhite(Square* source)
{
    if (source->getColor() == WHITE)
    {
        return true;
    }
    false;
}

bool Board::doMove()
{
    string position;
    int x1, x2, y1, y2;
    bool stop = false;
    Square* source;
    Square* destination;
    while (!stop)
    {
        (getTurnColor() == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
        cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
        cin >> position;
        x1 = position[0] - 48;
        y1 = position[1] - 48;
        x2 = position[2] - 48;
        y2 = position[3] - 48;
        source = getSquare(x1, y1);
        destination = getSquare(x2, y2);

        if (getSquare(x1, y1)->getColor() == turn)
        {
            if (!makeMoveIfValid(x1, y1, x2, y2))
            {
                cout << "Invalid move, try again." << endl;
            }
            else
            {
                stop = true;
            }
        }
        else
        {
            cout << "That's not your piece. Try again." << endl;
        }
    }

    if (checkIfDestinationIsKing(destination))
    {
        if (checkIfSourceIsWhite(source))
        {
            cout << "WHITE WINS" << endl;
        }
        else
        {
            cout << "BLACK WINS" << endl;
        }
        return false;
    }

    if (getTurnColor() == BLACK)
    {
        setTurnColor(WHITE);
    }
    else
    {
        setTurnColor(BLACK);
    }

    return true;
}

void Board::setPiecesWithoutPawnsAndEmpty()
{
    board[0][0].setPieceAndColor(new Rook(), WHITE);
    board[1][0].setPieceAndColor(new Knight(), WHITE);
    board[2][0].setPieceAndColor(new Bishop(), WHITE);
    board[3][0].setPieceAndColor(new Queen(), WHITE);
    board[4][0].setPieceAndColor(new King(), WHITE);
    board[5][0].setPieceAndColor(new Bishop(), WHITE);
    board[6][0].setPieceAndColor(new Knight(), WHITE);
    board[7][0].setPieceAndColor(new Rook(), WHITE);

    board[0][7].setPieceAndColor(new Rook(), BLACK);
    board[1][7].setPieceAndColor(new Knight(), BLACK);
    board[2][7].setPieceAndColor(new Bishop(), BLACK);
    board[3][7].setPieceAndColor(new Queen(), BLACK);
    board[4][7].setPieceAndColor(new King(), BLACK);
    board[5][7].setPieceAndColor(new Bishop(), BLACK);
    board[6][7].setPieceAndColor(new Knight(), BLACK);
    board[7][7].setPieceAndColor(new Rook(), BLACK);
}

void Board::setPawns()
{
    for (int i = 0; i < 8; i++)
    {
        board[i][1].setPieceAndColor(new Pawn(), WHITE);
        board[i][6].setPieceAndColor(new Pawn(), BLACK);
    }
}

void Board::setEmptyPieces()
{
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[j][i].setPieceAndColor(new Empty(), NONE);
        }
    }
}

void Board::setPiecesOnTheDesk()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j].setX(i);
            board[i][j].setY(j);
        }
    }
}

void Board::setBoard()
{
    setPiecesWithoutPawnsAndEmpty();

    setPawns();

    setEmptyPieces();

    setPiecesOnTheDesk();
}

bool Board::playGame()
{
    system("cls");
    printBoard();
    return doMove();
}

bool Board::checkOutOfBounds(int x1, int y1, int x2, int y2)
{
    if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 8)
    {
        return true;
    }
    return false;
}

bool Board::checkForDifferentColorPieces(Square* source, Square* destination)
{
    if (source->getColor() == destination->getColor() && destination->getColor() != NONE)
    {
        return false;
    }
    return true;
}

bool Board::checkIfSourcePieceIsNoEmpty(Square* source)
{
    if (source->getPiece()->getName() == 'K' || source->getPiece()->getName() == 'Q' || source->getPiece()->getName() == 'B' ||
            source->getPiece()->getName() == 'H' || source->getPiece()->getName() == 'R' || source->getPiece()->getName() == 'P' ||
            source->getPiece()->getName() == 'k' || source->getPiece()->getName() == 'q' || source->getPiece()->getName() == 'b' ||
            source->getPiece()->getName() == 'h' || source->getPiece()->getName() == 'r' || source->getPiece()->getName() == 'p')
    {
        return true;
    }
    return false;
}

bool Board::makeMoveIfValid(int x1, int y1, int x2, int y2)
{
    if (checkOutOfBounds(x1, y1, x2, y2))
    {
        cout << "One of your inputs was out of bounds" << endl;
        return false;
    }

    Square* source = getSquare(x1, y1);
    Square* destination = getSquare(x2, y2);

    if (!checkForDifferentColorPieces(source, destination))
    {
        cout << "Invalid move: cannot land on your own piece" << endl;
        return false;
    }

    int sourceX = source->getX();
    int sourceY = source->getY();
    int destinationX = destination->getX();
    int destinationY = destination->getY();

    if (checkIfSourcePieceIsNoEmpty(source))
    {
        if (source->getPiece()->moveMe(sourceX, sourceY, destinationX, destinationY, source->getColor(), destination->getColor()))
        {
            destination->setSpace(source);
            source->setEmpty();
            return true;
        }
    }

    if (!checkIfSourcePieceIsNoEmpty(source))
    {
        cout << "You do not have a piece there" << endl;
    }

    return false;
}
