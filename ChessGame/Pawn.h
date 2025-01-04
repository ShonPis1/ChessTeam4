#pragma once

#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(const int x, const int y, bool isWhite);

    ~Pawn();

    bool isMoveLegal(const Coord& destination, Piece *boardStatus[8][8]) const;
};