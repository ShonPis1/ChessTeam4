#pragma once

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(const int y, const int x, bool isWhite);

    ~Queen();

    bool isMoveLegal(const Coord& dest) const override;

    Piece* getCopy() const override;
};