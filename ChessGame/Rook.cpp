#include "Rook.h"

Rook::Rook(int y, int x, bool isWhite) : Piece(y, x, isWhite ? 'R' : 'r', isWhite) {}

Rook::~Rook() {}

bool Rook::isMoveLegal(const Coord& dest) const {
    int dy = std::abs(dest.getY() - _position.getY());
    int dx = std::abs(dest.getX() - _position.getX());

    return (dy == 0 || dx == 0); //can only move in straight lines
}

Piece* Rook::getCopy() const{
    return new Rook(*this);
}
