#include <iostream>
#include "Piece.h"

void Piece::setName(char newName)
{
    this->name = newName;
}

char Piece::getName() const
{
    return this->name;
}
