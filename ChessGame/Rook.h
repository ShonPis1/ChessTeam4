#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:

    Rook(int y, int x, bool isWhite);

    ~Rook();

    bool isMoveLegal(const Coord& dest) const override;

    Piece* getCopy() const override;
};