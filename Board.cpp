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
            Color pieceColor = board[i][j].getColor();

            switch (thisPiece->getName())
            {
            case 'K':
                (pieceColor == WHITE) ? cout << " K " : cout << " k ";
                break;
            case 'Q':
                (pieceColor == WHITE) ? cout << " Q " : cout << " q ";
                break;
            case 'B':
                (pieceColor == WHITE) ? cout << " B " : cout << " b ";
                break;
            case 'H':
                (pieceColor == WHITE) ? cout << " H " : cout << " h ";
                break;
            case 'R':
                (pieceColor == WHITE) ? cout << " R " : cout << " r ";
                break;
            case 'P':
                (pieceColor == WHITE) ? cout << " P " : cout << " p ";
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

bool Board::doMove()
{
    string position;
    int sourceX, sourceY, destinationX, destinationY;
    bool stop = false;
    bool isDestinationKing = false;
    Square* source;
    Square* destination;
    while (!stop)
    {
        (getTurnColor() == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
        cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
        cin >> position;
        sourceX = position[0] - 48;
        sourceY = position[1] - 48;
        destinationX = position[2] - 48;
        destinationY = position[3] - 48;

        source = getSquare(sourceX, sourceY);
        destination = getSquare(destinationX, destinationY);

        Color sourceColor = source->getColor();
        if (sourceColor == turn)
        {
            if (checkIfDestinationIsKing(destination))
            {
                isDestinationKing = true;
            }
            if (!makeMoveIfValid(source, destination))
            {
                cout << "Invalid move, try again." << endl;
                isDestinationKing = false;
            }
            else
            {
                stop = true;
                if (isDestinationKing)
                {
                    if (getTurnColor() == WHITE)
                    {
                        cout << "WHITE WINS" << endl;
                    }
                    else
                    {
                        cout << "BLACK WINS" << endl;
                    }
                    return false;
                }
            }
        }
        else
        {
            cout << "That's not your piece. Try again." << endl;
        }
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

void Board::setAllPiecesOnTheDesk()
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

    setAllPiecesOnTheDesk();
}

bool Board::playGame()
{
    system("cls");
    printBoard();
    return doMove();
}

bool Board::checkOutOfBounds(Square* source, Square* destination)
{
    int sourceX = source->getX();
    int sourceY = source->getY();
    int destinationX = destination->getX();
    int destinationY = destination->getY();

    if (sourceX < 0 || 7 < sourceX ||
            sourceY < 0 || 7 < sourceY ||
            destinationX < 0 || 7 < destinationX ||
            destinationY < 0 || 7 < destinationY)
    {
        return true;
    }

    return false;
}

bool Board::checkForSameColorPieces(Square* source, Square* destination)
{
    if (source->getColor() == destination->getColor() && destination->getColor() != NONE)
    {
        return true;
    }
    return false;
}

bool Board::checkIfSourcePieceIsEmpty(Square* source)
{
    if (source->getPiece()->getName() == 'K' || source->getPiece()->getName() == 'Q' || source->getPiece()->getName() == 'B' ||
            source->getPiece()->getName() == 'H' || source->getPiece()->getName() == 'R' || source->getPiece()->getName() == 'P' ||
            source->getPiece()->getName() == 'k' || source->getPiece()->getName() == 'q' || source->getPiece()->getName() == 'b' ||
            source->getPiece()->getName() == 'h' || source->getPiece()->getName() == 'r' || source->getPiece()->getName() == 'p')
    {
        return false;
    }
    return true;
}

bool Board::makeMoveIfValid(Square* source, Square* destination)
{
    if (checkOutOfBounds(source, destination))
    {
        cout << "One of your inputs was out of bounds" << endl;
        return false;
    }

    if (checkForSameColorPieces(source, destination))
    {
        cout << "Invalid move: cannot land on your own piece" << endl;
        return false;
    }

    if (!checkIfSourcePieceIsEmpty(source))
    {
        int sourceX = source->getX();
        int sourceY = source->getY();
        int destinationX = destination->getX();
        int destinationY = destination->getY();

        pair<int,int> sourceCoordinates = make_pair(sourceX, sourceY);
        pair<int,int> destinationCoordinates = make_pair(destinationX, destinationY);
        Color sourceColor = source->getColor();
        Color destinationColor = destination->getColor();

        if (source->getPiece()->moveMe(sourceCoordinates, destinationCoordinates, sourceColor, destinationColor))
        {
            destination->setSpace(source);
            source->setEmpty();
            return true;
        }
    }

    if (checkIfSourcePieceIsEmpty(source))
    {
        cout << "You do not have a piece there" << endl;
    }

    return false;
}
