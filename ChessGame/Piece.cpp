#include "Piece.h"

Piece::Piece(int y, int x, char type, bool isWhite) : _position(y, x), _type(type), _isWhite(isWhite), _didMoved(false) {}

Piece::~Piece() {}

void Piece::setPosition(const Coord& newPosition)
{ 
	_didMoved = true;
	_position = newPosition;
}

void Piece::setDidMoved(bool didMoved) { _didMoved = didMoved; }

const bool Piece::didMoved() const { return _didMoved; }

const bool Piece::iswhite() const { return _isWhite; }

Coord Piece::getPosition() const { return _position; }

const char Piece::getType() const { return _type; }