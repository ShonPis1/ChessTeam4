#pragma once

#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop(const int y, const int x, bool isWhite);

    ~Bishop();

    bool isMoveLegal(const Coord& dest) const override;

    Piece* getCopy() const override;
};