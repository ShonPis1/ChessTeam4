#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(const int y, const int x, bool isWhite);

    ~Knight();

    bool isMoveLegal(const Coord& dest) const override;

    Piece* getCopy() const override;
};