#include "Knight.h"
#include <cmath>

Knight::Knight(const int x, const int y, bool isWhite) : Piece(x, y, isWhite ? 'N' : 'n', isWhite) {}

Knight::~Knight() {}

bool Knight::isMoveLegal(const Coord& destination) const { //didnt checked if a piece block his path;
    int dx = std::abs(destination.getX() - _position.getX()); // delta x of the move coordinates 
    int dy = std::abs(destination.getY() - _position.getY()); // delta y of the move coordinates 

    return ((dx == 2 && dy == 1) || (dx == 1 && dy = 2)); //Knight movement is on 1 axis move 1 and on the other move 2
}

Piece* Knight::getCopy() const{
    return new Knight(*this);
}