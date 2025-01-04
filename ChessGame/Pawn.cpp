#include "Pawn.h"
#include <cmath>

Pawn::Pawn(const int x, const int y, bool isWhite) : Piece(x, y, isWhite ? 'P' : 'p', isWhite) {}

Pawn::~Pawn() {}

bool Pawn::isMoveLegal(const Coord& destination) const { return false; }

bool Pawn::isMoveLegal(const Coord& destination, Piece *boardStatus[8][8]) const {
	int dx = destination.getX() - _position.getX();
	int dy = std::abs(destination.getY() - _position.getY()); // delta x of the move coordinates 
	
																								
	if ((_isWhite && dx <= 0) || (_isWhite && dx >= 0)) return false; // can only move forwards

	dx = std::abs(dx);

	if (dx == 2) {
		if ((_isWhite && _position.getX() != 1) || (!_isWhite && _position.getX() != 6) || dy != 0) 
			return false;
		
	}else if (dx != 1)  return false; 

	if (dy == 0) {
		if (boardStatus[destination.getX()][destination.getY()] != nullptr)  return false; //cant capture a piece using this move
	}else if (dy == 1){
		if (boardStatus[destination.getX()][destination.getY()] == nullptr)  return false;  //have to capture a piece using this move
	}else  return false; 

	return true;
}

Piece* Pawn::getCopy() const{
	return new Pawn(*this);
}