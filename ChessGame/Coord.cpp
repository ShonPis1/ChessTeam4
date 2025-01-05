#include "Coord.h"

Coord::Coord(int y, int x) : _x(x), _y(y) {}

Coord::Coord() {}

Coord::~Coord() {}

void Coord::setX(int x) { _x = x; }

void Coord::setY(int y) { _y = y; }

int Coord::getX() const { return _x; }

int Coord::getY() const { return _y; }

bool Coord::isValid() const {
	return _x >= 0 && _x < BOARD_SIZE && _y >= 0 && _y < BOARD_SIZE;
}

bool Coord::operator==(const Coord& other) const {
	return _x == other._x && _y == other._y;
}