#pragma once

#include "Piece.h"

class King : public Piece
{
public:
    King(const Coord& position, bool isWhite);
    King(const int x, const int y, bool isWhite);

    ~King();

    bool isMoveLegal(const Coord& destination) const override;
};