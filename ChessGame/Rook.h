#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(const Coord& position, bool isWhite);
    Rook(const int x, const int y, bool isWhite);

    ~Rook();

    bool isMoveLegal(const Coord& destination) const override;
};