#pragma once

#include "Coord.h"
#include <cmath>

class Piece
{
public:
	Piece(int y, int x, char type, bool isWhite);
	~Piece();

	void setPosition(const Coord& newPosition);
	virtual Piece* getCopy() const = 0;

	const bool iswhite() const;
	Coord getPosition() const;
	const char getType() const;

	/*checks if the movement of the piece is legal to reach the destination coordinate 
	input: the destination coordinate 
	output: if the move is legal according to the piece's movement rules */
	virtual bool isMoveLegal(const Coord& dest) const = 0;

protected:
	bool _isWhite;
	Coord _position;
	char _type;
};