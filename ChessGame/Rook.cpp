#include "Rook.h"
#include <cmath>

Rook::Rook(const Coord& position, bool isWhite) : Piece(position, isWhite ? 'R' : 'r', isWhite) {}
Rook::Rook(const int x, const int y, bool isWhite) : Piece(x, y, isWhite ? 'R' : 'r', isWhite) {}

Rook::~Rook() {}

bool Rook::isMoveLegal(const Coord& destination) const { //didnt checked if a piece block his path;
    int dx = std::abs(destination.getX() - _position.getX()); // delta x of the move coordinates 
    int dy = std::abs(destination.getY() - _position.getY()); // delta y of the move coordinates 

    return (dx == 0 || dy == 0); // rook can only move in straight lines
}