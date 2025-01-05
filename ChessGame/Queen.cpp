#include "Queen.h"
#include <cmath>

Queen::Queen(const int y, const int x, bool isWhite) : Piece(y, x, isWhite ? 'Q' : 'q', isWhite) {}

Queen::~Queen() {}

bool Queen::isMoveLegal(const Coord& dest) const {
	int dy = std::abs(dest.getY() - _position.getY()); 
	int dx = std::abs(dest.getX() - _position.getX()); 

	return (dy == 0 || dx == 0 || dx == dy); //can only move in straight lines and diognals
}

Piece* Queen::getCopy() const {
	return new Queen(*this);
}