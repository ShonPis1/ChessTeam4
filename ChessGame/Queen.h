#pragma once

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(const int x, const int y, bool isWhite);

    ~Queen();

    bool isMoveLegal(const Coord& destination) const override;

    Piece* getCopy() const override;
};