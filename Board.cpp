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
			case 'K': (thisColor == WHITE) ? cout << " K " : cout << " k ";
				break;
			case 'Q': (thisColor == WHITE) ? cout << " Q " : cout << " q ";
				break;
			case 'B':(thisColor == WHITE) ? cout << " B " : cout << " b ";
				break;
			case 'H':(thisColor == WHITE) ? cout << " H " : cout << " h ";
				break;
			case 'R': (thisColor == WHITE) ? cout << " R " : cout << " r ";
				break;
			case 'P': (thisColor == WHITE) ? cout << " P " : cout << " p ";
				break;
			case 'E': cout << " " << "\21" << " ";
				break;
			default: cout << "XXX";
				break;
			}
		}
		cout << endl;
	}
}

bool Board::doMove()
{
	string position;
	int x1, x2, y1, y2;
	bool stop = false;
	while (!stop)
	{
		(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
		cin >> position;
		x1 = position[0] - 48;
		y1 = position[1] - 48;
		x2 = position[2] - 48;
		y2 = position[3] - 48;
		if (getSquare(x1, y1)->getColor() == turn)
		{
			if (makeMove(x1, y1, x2, y2) == false)
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

	if (getSquare(x2, y2)->getPiece()->getName() == 'K' || getSquare(x2, y2)->getPiece()->getName() == 'k')
    {
        if (getSquare(x1, y1)->getColor() == WHITE)
		{
			cout << "WHITE WINS" << endl;
		}
		else
		{
			cout << "BLACK WINS" << endl;
		}
		return false;
    }

	if (turn == BLACK)
    {
        turn = WHITE;
    }
	else
    {
        turn = BLACK;
    }

	return true;
}

void Board::setBoard()
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

	for (int i = 0; i < 8; i++)
	{
		board[i][1].setPieceAndColor(new Pawn(), WHITE);
		board[i][6].setPieceAndColor(new Pawn(), BLACK);
	}

	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
        {
            board[j][i].setPieceAndColor(new Empty(), NONE);
        }
	}

	for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
		{
			board[i][j].setX(i);
			board[i][j].setY(j);
		}
    }
}

bool Board::playGame()
{
	system("cls");
	printBoard();
	return doMove();
}

bool Board::makeMove(int x1, int y1, int x2, int y2)
{
	//Checking for turns will be done previous to this
	if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 8)
	{
		cout << "One of your inputs was our of bounds" << endl;
		return false;
	}

	Square* src = getSquare(x1, y1);
	Square* dest = getSquare(x2, y2);

	if (src->getColor() == dest->getColor() && dest->getColor() != NONE)
	{
		cout << "Invalid move: cannot land on your own piece" << endl;
		return false;
	}

    int src_x = src->getX();
	int src_y = src->getY();
	int dest_x = dest->getX();
	int dest_y = dest->getY();

	if (src->getPiece()->getName() == 'K' || src->getPiece()->getName() == 'Q' || src->getPiece()->getName() == 'B' ||
        src->getPiece()->getName() == 'H' || src->getPiece()->getName() == 'R' || src->getPiece()->getName() == 'P')
    {
        if (src->getPiece()->moveMe(src_x, src_y, dest_x, dest_y, src->getColor(), dest->getColor()))
        {
            dest->setSpace(src);
            src->setEmpty();
            return true;
        }
    }

	if (src->getPiece()->getName() == 'E')
    {
        cout << "You do not have a piece there" << endl;
        return false;
    }

    return false;
}
