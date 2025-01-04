#include "Queen.h"
#include <cmath>

Queen::Queen(const int x, const int y, bool isWhite) : Piece(x, y, isWhite ? 'Q' : 'q', isWhite) {}

Queen::~Queen() {}

bool Queen::isMoveLegal(const Coord& destination) const { 
	int dx = std::abs(destination.getX() - _position.getX()); // delta x of the move coordinates 
	int dy = std::abs(destination.getY() - _position.getY()); // delta y of the move coordinates

	return (dx == 0 || dy == 0 || dx == dy); // queen can only move in straight lines and diognals
}

Piece* Queen::getCopy() const {
	return new Queen(*this);
}