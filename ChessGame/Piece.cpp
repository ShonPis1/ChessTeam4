#include "Piece.h"

Piece::Piece(int y, int x, char type, bool isWhite) : _position(y, x), _type(type), _isWhite(isWhite) {}

Piece::~Piece() {}

void Piece::setPosition(const Coord& newPosition) { _position = newPosition; }

const bool Piece::iswhite() const { return _isWhite; }

Coord Piece::getPosition() const { return _position; }

const char Piece::getType() const { return _type; }