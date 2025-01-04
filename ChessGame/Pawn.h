#pragma once

#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(const int x, const int y, bool isWhite);

    ~Pawn();

    bool isMoveLegalPawn(const Coord& destination, Piece* const boardStatus[8][8]) const;
    bool isMoveLegal(const Coord& destination) const override;

    Piece* getCopy() const override;
};