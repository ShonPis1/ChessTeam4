#include "Piece.h"

Piece::Piece(const Coord& position, char type, bool isWhite) : _position(position), _type(type), _isWhite(isWhite) {}
Piece::Piece(const int x, const int y, char type, bool isWhite) : _type(type), _isWhite(isWhite) 
{
	Coord position(x, y);
	_position = position;
}

Piece::~Piece() {}

void Piece::setPosition(const Coord& newPosition) { _position = newPosition; }

const bool Piece::iswhite() const { return _isWhite; }

Coord Piece::getPosition() const { return _position; }

const char Piece::getType() const { return _type; }

Piece Piece::operator=(const Piece& other)
{
	Piece temp(other.getPosition(), other.getType(), other.iswhite());
	return temp;
}