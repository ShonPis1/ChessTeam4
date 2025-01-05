#include "Pawn.h"

Pawn::Pawn(const int y, const int x, bool isWhite) : Piece(y, x, isWhite ? 'P' : 'p', isWhite) {}

Pawn::~Pawn() {}

bool Pawn::isMoveLegal(const Coord& dest) const { return true; }

bool Pawn::isMoveLegalPawn(const Coord& dest, Piece* const boardStatus[BOARD_SIZE][BOARD_SIZE]) const {
	int dy = dest.getY() - _position.getY();
	int dx = std::abs(dest.getX() - _position.getX());  
																				
	if ((_isWhite && dy <= 0) || (!_isWhite && dy >= 0)) return false; //can move only forwards

	dy = std::abs(dy);

	if (dy == 2) {  //can move 2 squares only at start position 
		if ((_isWhite && _position.getY() != 1) || (!_isWhite && _position.getY() != 6) || dx != 0) 
			return false;
		
	}else if (dy != 1)  return false; 

	if (dx == 0) {
		if (boardStatus[dest.getY()][dest.getX()] != nullptr)  return false; //cant capture a piece using this move
	}else if (dx == 1){
		if (boardStatus[dest.getY()][dest.getX()] == nullptr)  return false;  //have to capture a piece using this move
	}else  return false; 

	return true;
}

Piece* Pawn::getCopy() const{
	return new Pawn(*this);
}