#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(int x, int y, bool isWhite);

    ~Rook();

    bool isMoveLegal(const Coord& destination) const override;
};