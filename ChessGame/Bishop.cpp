#include "Bishop.h"

Bishop::Bishop(const int y, const int x, bool isWhite) : Piece(y, x, isWhite ? 'B' : 'b', isWhite) {}

Bishop::~Bishop() {}

bool Bishop::isMoveLegal(const Coord& dest) const { 
    int dy = std::abs(dest.getY() - _position.getY()); //delta y  
    int dx = std::abs(dest.getX() - _position.getX()); //delta x 
    
    return dy == dx; //diognal lines 
}

Piece* Bishop::getCopy() const{
    return new Bishop(*this);
}