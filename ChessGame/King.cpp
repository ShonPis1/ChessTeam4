#include "King.h"
#include <cmath>

King::King(const Coord& position, bool isWhite) : Piece(position, isWhite ? 'K' : 'k', isWhite) {}

King::~King() {}

bool King::isMoveLegal(const Coord& destination) const {
    int dx = std::abs(destination.getX() - _position.getX()); // delta x of the move coordinates 
    int dy = std::abs(destination.getY() - _position.getY()); // delta y of the move coordinates 

    return (dx <= 1 && dy <= 1); // king can move only one square in any direction
}