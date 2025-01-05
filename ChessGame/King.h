#pragma once

#include "Piece.h"

class King : public Piece
{
public:
    King(int y, int x, bool isWhite);

    ~King();

    bool isMoveLegal(const Coord& dest) const override;

    Piece* getCopy() const override;
};