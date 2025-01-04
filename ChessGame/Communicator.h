#pragma once

#include "Board.h"
using std::string;

enum chessColumn{a = 0, b, c, d, e, f, g, h};

class Communicator : public Board
{
public:
	char* sendBoard();
	Coord* getNewMove(const std::string& move);

private:
	char boardString[66];
};