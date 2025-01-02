#pragma once

#include "Piece.h"

class King : public Piece
{
public:
    King(int x, int y, bool isWhite);

    ~King();

    bool isMoveLegal(const Coord& destination) const override;
};