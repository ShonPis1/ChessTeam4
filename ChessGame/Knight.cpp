#include "Knight.h"

Knight::Knight(const int y, const int x, bool isWhite) : Piece(y, x, isWhite ? 'N' : 'n', isWhite) {}

Knight::~Knight() {}

bool Knight::isMoveLegal(const Coord& dest) const {
    int dy = std::abs(dest.getY() - _position.getY()); //delta y 
    int dx = std::abs(dest.getX() - _position.getX()); //delta x 
    
    return ((dy == 2 && dx == 1) || (dx == 2 && dy == 1));
}

Piece* Knight::getCopy() const{
    return new Knight(*this);
}