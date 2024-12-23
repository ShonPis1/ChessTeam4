#pragma once // check

#include "Piece.h"

class nullPiece : public Piece
{
public:
    nullPiece(const Coord& position);

    ~nullPiece();
};