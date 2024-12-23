#pragma once

#include "Piece.h"

class NullPiece : public Piece
{
public:
    NullPiece(const Coord& position);

    ~NullPiece();
};