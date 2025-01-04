#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(const Coord& position, bool isWhite);
    Knight(const int x, const int y, bool isWhite);

    ~Knight();

    bool isMoveLegal(const Coord& destination) const override;
};