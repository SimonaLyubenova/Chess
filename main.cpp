#include <iostream>
#include <string>
#include "Square.h"
#include "Board.h"

using namespace std;

int main()
{
	Board board;
	string inputString;
	bool newgame = true;
	cout << "Welcome to the Chess Game" << endl << endl;
	cout << "Enter any key to continue" << endl;
	cin >> inputString;

	while(newgame)
    {
		board.setBoard();
		while (board.playGame());
		cout << "Do you want to play again? (y for yes, anything else for no) ";
		cin >> inputString;
		if (inputString != "y")
        {
            newgame = false;
        }
	}

	return 0;
}
