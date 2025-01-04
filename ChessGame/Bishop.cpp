#include "Bishop.h"
#include <cmath>

Bishop::Bishop(const int x, const int y, bool isWhite) : Piece(x, y, isWhite ? 'B' : 'b', isWhite) {}

Bishop::~Bishop() {}

bool Bishop::isMoveLegal(const Coord& destination) const { //didnt checked if a piece block his path;
    int dx = std::abs(destination.getX() - _position.getX()); // delta x of the move coordinates 
    int dy = std::abs(destination.getY() - _position.getY()); // delta y of the move coordinates 

    return (dx == dy); // Diognal lines, delta x is delta y
}

Piece* Bishop::getCopy() const{
    return new Bishop(*this);
}