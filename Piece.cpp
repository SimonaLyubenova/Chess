#include <iostream>
#include "Piece.h"

void Piece::setName(char newName)
{
    this->name = newName;
}

char Piece::getName()
{
    return this->name;
}
