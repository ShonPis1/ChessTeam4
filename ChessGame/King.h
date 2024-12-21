#pragma once

#include "Piece.h"

class King : public Piece
{
public:
    King(const Coord& position, bool isWhite);

    ~King();

    bool isMoveLegal(const Coord& destination) const override;
};