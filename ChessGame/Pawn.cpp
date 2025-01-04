#include "Pawn.h"
#include <cmath>

Pawn::Pawn(const int x, const int y, bool isWhite) : Piece(x, y, isWhite ? 'P' : 'p', isWhite) {}

Pawn::~Pawn() {}

bool Pawn::isMoveLegal(const Coord& destination) const { }

bool Pawn::isMoveLegal(const Coord& destination, Piece *boardStatus[8][8]) const {
	int dx = std::abs(destination.getX() - _position.getX()); // delta x of the move coordinates 
	int dy = destination.getY() - _position.getY();
																								
	if (_isWhite) // can only move forwards
	{
		if (dy >= 0) { return false; }
	}
	else
	{
		if (dy <= 0) { return false; }
	}

	dy = std::abs(dy);

	if (dy == 2) 
	{
		if (_position.getY() != 1 || _position.getY() != 6 || dx != 0) { return false; } // can only move 2 coord in first position
	}
	else if (dy != 1) { return false; } // have to move either 1 or 2
	if (dx == 0) 
	{
		if (boardStatus[destination.getX()][destination.getY()] != 0) { return false; } //cant capture a piece using this move
	}
	else if (dx == 1)
	{
		if (boardStatus[destination.getX()][destination.getY()] == 0) { return false; } //have to capture a piece using this move
	}
	else { return false; }
}

Piece* Pawn::getCopy() const{
	return new Pawn(*this);
}