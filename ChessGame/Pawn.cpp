#include "Pawn.h"
#include <cmath>

Pawn::Pawn(const int x, const int y, bool isWhite) : Piece(x, y, isWhite ? 'P' : 'p', isWhite) {}

Pawn::~Pawn() {}

bool Pawn::isMoveLegal(const Coord& destination) const { return false; }

bool Pawn::isMoveLegalPawn(const Coord& destination, Piece* const boardStatus[8][8]) const {
	int dx = std::abs(destination.getX() - _position.getX()); // delta x of the move coordinates 
	int dy = destination.getY() - _position.getY();

	if (_isWhite) // can only move forwards
	{
		if (dx <= 0) { return false; }
	}
	else
	{
		if (dx >= 0) { return false; }
	}

	dx = std::abs(dx);

	if (dx == 2)
	{
		if ((_isWhite && _position.getX() != 1) || (!_isWhite && _position.getX() != 6) || dy != 0) { return false; } // can only move 2 coord in first position
	}
	else if (dx != 1) { return false; } // have to move either 1 or 2
	if (dy == 0)
	{
		if (boardStatus[destination.getX()][destination.getY()] != nullptr) { return false; } //cant capture a piece using this move
	}
	else if (dy == 1)
	{
		if (boardStatus[destination.getX()][destination.getY()] == nullptr) { return false; } //have to capture a piece using this move
	}
	else { return false; }

	return true;
}

Piece* Pawn::getCopy() const {
	return new Pawn(*this);
}