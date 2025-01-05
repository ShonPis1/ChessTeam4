#include "King.h"

King::King(int y, int x, bool isWhite) : Piece(y, x, isWhite ? 'K' : 'k', isWhite) {}

King::~King() {}

bool King::isMoveLegal(const Coord& dest) const {
    int dy = std::abs(dest.getY() - _position.getY()); //delta y 
    int dx = std::abs(dest.getX() - _position.getX()); //delta x 
    
    return (dy <= 1 && dx <= 1); //only one square in any direction
}

Piece* King::getCopy() const{
    return new King(*this);
}
