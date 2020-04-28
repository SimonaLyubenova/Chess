#include <iostream>
#include "Board.h"

using namespace std;

Square board[8][8];
int main()
{
    Board desk;
    string inputString;
    bool newgame = true;
    cout << "Welcome to the Chess Game" << endl << endl;
    cout << "Enter any key to continue" << endl;
    cin >> inputString;

    while(newgame)
    {
        desk.setBoard();
        while (desk.playGame());
        cout << "Do you want to play again? (y for yes, anything else for no) ";
        cin >> inputString;
        if (inputString != "y")
        {
            newgame = false;
        }
        else
        {
            newgame = true;
        }
    }

    return 0;
}
