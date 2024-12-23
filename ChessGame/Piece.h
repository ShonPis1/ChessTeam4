#pragma once

#include "Coord.h"

class Piece
{
public:
	Piece(const Coord& position, char type, bool isWhite);

	~Piece();

	void setPosition(const Coord& newPosition);

	const bool iswhite() const;
	Coord getPosition() const;
	const char getType() const;

	Piece operator=(const Piece& other);

	/*checks if the movement of the piece is legal to reach the destination coordinate 
	input: the destination coordinate 
	output: if the move is legal according to the piece's movement rules */
	virtual bool isMoveLegal(const Coord& destination) const;// = 0; // check

protected:
	const bool _isWhite;
	Coord _position;
	const char _type;
};