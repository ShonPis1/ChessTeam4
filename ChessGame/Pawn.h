#pragma once

#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(const int y, const int x, bool isWhite);

    ~Pawn();

    /*checks if a move is legal by the special pawn movement rules
    input: the destination coordinate, the current board satus
    output: if the move is legal */
    bool isMoveLegalPawn(const Coord& dest, Piece* const boardStatus[BOARD_SIZE][BOARD_SIZE]) const;

    bool isMoveLegal(const Coord& dest) const override;

    Piece* getCopy() const override;
};