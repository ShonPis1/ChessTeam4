#pragma once

#include "Coord.h"

class Piece
{
public:
	Piece(Coord position, char type, bool isBlack);

	virtual ~Piece();

	void setPosition(const Coord& newPosition);

	const bool iswhite() const;
	Coord getPosition() const;
	const char getType() const;


	/*checks if the movement of the piece is legal to reach the destination coordinate 
	input: the destination coordinate 
	output: if the move is legal according to the piece's movement rules */
	virtual bool isValid(const Coord& destination) const = 0; 

protected:
	const bool _isWhite;
	Coord _position;
	const char _type;
};