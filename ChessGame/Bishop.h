#pragma once

#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop(const int x, const int y, bool isWhite);

    ~Bishop();

    bool isMoveLegal(const Coord& destination) const override;

    Piece* getCopy() const override;
};