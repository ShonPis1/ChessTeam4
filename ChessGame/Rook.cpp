#include "Rook.h"
#include <cmath>

Rook::Rook(int x, int y, bool isWhite) : Piece(x, y, isWhite ? 'R' : 'r', isWhite) {}

Rook::~Rook() {}

bool Rook::isMoveLegal(const Coord& destination) const {
    int dx = std::abs(destination.getX() - _position.getX());  // delta x of the move coordinates 
    int dy = std::abs(destination.getY() - _position.getY());  // delta y of the move coordinates 

    return (dx == 0 || dy == 0); // rook can only move in straight lines
}

Piece* Rook::getCopy() const{
    return new Rook(*this);
}
