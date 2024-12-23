#include "Coord.h"

Coord::Coord() : _x(0), _y(0) {}
Coord::Coord(int x, int y) : _x(x), _y(y) {}

Coord::~Coord() {}

void Coord::setX(int x) { _x = x; }

void Coord::setY(int y) { _y = y; }

int Coord::getX() const { return _x; }

int Coord::getY() const { return _y; }

bool Coord::isValid() const {
	return _x >= 0 && _x < 8 && _y >= 0 && _y < 8;
}

bool Coord::operator!=(const Coord& other) const {
	return _x != other._x || _y != other._y;
}