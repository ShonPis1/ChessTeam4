#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(const int x, const int y, bool isWhite);

    ~Knight();

    bool isMoveLegal(const Coord& destination) const override;

    Piece* getCopy() const override;
};